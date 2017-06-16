#include <iostream>
#include <GameEngine.hpp>
#include <dlfcn.h>
#include <thread>
#include <unistd.h>

int setLib(GameEngine **gameEngine, int libID){
	GameEngine *game = *gameEngine;
	std::cout << "Your Lib: " << libID << std::endl;
	switch (libID){
		case 1:
			game->setLibHandler(dlopen("libs/lib1-opengl/libOpenGL.so", RTLD_NOW));
			break ;
		case 2:
			game->setLibHandler(dlopen("libs/lib2-sdl/libSDL.so", RTLD_NOW));
			break ;
		case 3:
			game->setLibHandler(dlopen("libs/lib3-sfml/libSFML.so", RTLD_NOW));
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

int launchGame(int winWidth, int winHeight, int libID){
	GameEngine *game = new GameEngine(winWidth, winHeight, libID);
	int direction;
	if (!setLib(&game, libID))
		return 0;
	while (!game->getExit()){
		usleep(50000);
		if ((direction = game->getLibrary()->keyhook()) < 0)
			break;
		if (game->getSnake()->detectCollision(winWidth, winHeight)){
			break;
		};
        game->getSnake()->update(direction);
        if (game->checkEat()) {
            game->getSnake()->addPart();
            delete(game->getFood());
            game->setFood(new Food(game->getWinWidth(), game->getWinHeight(), game->getSnake()->getParts()));
        };
		game->getLibrary()->print(game->getSnake()->getParts(), game->getFood());
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
		return 0;
	return 1;
}

int main(int argc, char **argv){
	int libID;
	try{
		if (!checkArgs(argc, argv))
			throw std::runtime_error("Format should be \"nibbler [width] [height]\"");
		else {
			while(1) {
				libID = 0;
				std::cout << "Please select the graphics library you'd like to use:" << std::endl;
				std::cout << "\t1. OpenGL" << std::endl;
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
		}
	} catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}