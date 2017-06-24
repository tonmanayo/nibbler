#include <iostream>
#include <GameEngine.hpp>
#include <dlfcn.h>
#include <thread>
#include <unistd.h>


int setLib(GameEngine **gameEngine, int libID){
	GameEngine *game = *gameEngine;
	std::cout << "Your Lib: " << libID << std::endl;
    if (game->getLibrary()) {
        game->destroyLib();
    }
	switch (libID){
		case 1:
			game->setLibHandler(dlopen("libSFMLv2.so", RTLD_NOW));
			break ;
		case 2:
			game->setLibHandler(dlopen("libSDL.so", RTLD_NOW));
			break ;
		case 3:
			game->setLibHandler(dlopen("libSFML.so", RTLD_NOW));
			break ;
		default:
			break;
	}
	if (!game->getLibHandler()) {
		std::cout << dlerror() << std::endl;
		throw std::runtime_error("Could not create Library handler.");
	}
	createLib_t* createLib = (createLib_t*) dlsym(game->getLibHandler(), "create");
	if (dlerror()){
		throw std::runtime_error(dlerror());
	} else {
		game->setLibrary(createLib(game->getWinWidth(), game->getWinHeight()));
	}

	dlerror();
	return 1;
}

void destroyLib(GameEngine **gameEngine){
    GameEngine *game = *gameEngine;
    game->destroyLib();
    dlclose(game->getLibHandler());
}

void checkTimer(int score, int *timer){
    if (score < 500)
        *timer = 50000;
    else {
        *timer -= (*timer / 2000);
    }
}

void changeLib(GameEngine *game, int value){
    if (game->getLibId() != value) {
        destroyLib(&game);
        switch (value) {
            case 5:
                setLib(&game, 1);
                game->setLibId(1);
                break;
            case 6:
                setLib(&game, 2);
                game->setLibId(2);
                break;
            case 7:
                setLib(&game, 3);
                game->setLibId(3);
                break;
            default:
                break;
        }
    }
}


int launchGame(int winWidth, int winHeight, int libID){
    int timer = 50000;
    int previousTimer = timer;
    int squareSize = 20;
    bool paused = false;
	GameEngine *game = new GameEngine(winWidth, winHeight, libID, squareSize);
	int direction;
	if (!setLib(&game, libID))
		return 0;
	while (!game->getExit()){
        direction = game->getLibrary()->keyhook();
		if (direction < 0)
			break;
        else if (direction == 5 || direction == 6 || direction == 7) {
            changeLib(game, direction);
            previousTimer = timer;
            timer = 500000000;
            std::cout << "paused" << std::endl;
            paused = true;
        } else if ((direction == 1 || direction == 2 || direction == 3) && paused) {
            timer = previousTimer;
            paused = false;
        }
		if (game->getSnake()->detectCollision(winWidth, winHeight)){
			break;
		};
        game->getSnake()->update(direction);
        if (game->checkEat()) {
            game->getSnake()->addPart();
            delete(game->getFood());
            game->setFood(new Food(game->getWinWidth(), game->getWinHeight(), game->getSnake()->getParts(), game->getSquareSize()));
            game->addScore(300);
        };
		if (game->checkBonus()) {
			game->getSnake()->addPart();
			delete(game->getBonus());
			game->setBonus(new Bonus(game->getWinWidth(), game->getWinHeight(), game->getSnake()->getParts()));
			game->addScore(900);
		};
		game->getLibrary()->print(game->getSnake()->getParts(), game->getFood(), game->getBonus(), std::to_string(game->getScore()));
        game->addScore(1);
        checkTimer(game->getScore(), &timer);
        usleep(timer);
	};
	delete game;
	return 1;
}

int checkArgs(int argc, char** args){
	int arg1;
	int arg2;
	if (args[1] && args[2]) {
		arg1 = std::atoi(args[1]);
		arg2 = std::atoi(args[2]);
	}
	if (argc != 3 || !arg1 || !arg2 || arg1 < 0 || arg2 < 0)
        throw std::runtime_error("Format should be \"nibbler [width] [height]\"");
    else if (arg1 < 640 || arg2 < 480 || arg1 > 1920 || arg2 > 1080)
        throw std::runtime_error("Incorrect window size (Min: 640 x 480px, Max: 1920 x 1080px)");
	return 1;
}

int main(int argc, char **argv){
	int libID;
	try{
		checkArgs(argc, argv);
        while(1) {
            libID = 0;
            std::cout << "Please select the graphics library you'd like to use:" << std::endl;
            std::cout << "\t1. SFMLv2" << std::endl;
            std::cout << "\t2. SDL" << std::endl;
            std::cout << "\t3. SFML" << std::endl << std::endl;
            std::cout << "Your choice: ";
            std::cin >> libID;
            if (!std::cin || libID > 3 || libID < 1) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "You have not entered a valid library id" << std::endl;
            } else
                break;
        }
        if(!libID){
            throw std::runtime_error("Could not assign your library ID.");
        } else if (!launchGame(std::atoi(argv[1]), std::atoi(argv[2]), libID)){
            throw std::runtime_error("Catastrophic game failure.");
        }
	} catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}