//
// Created by Kyle Gani on 2017/06/08.
//

#ifndef NIBBLER_GAMEENGINE_HPP
#define NIBBLER_GAMEENGINE_HPP

#include "Snake.hpp"
#include "Food.hpp"
#include "../libs/inc/ILibrary.hpp"

class GameEngine {
public:
	GameEngine(GameEngine const &src);
	GameEngine(int winWidth, int winHeight, int libId);
	GameEngine &operator=(GameEngine const &src);

	ILibrary*   getLibrary();
	void*       getLibHandler();
	int         getWinWidth();
	int         getWinHeight();
    Snake*      getSnake();
    Food*       getFood();
	bool        getExit();

	void        setLibrary(ILibrary* library);
	void        setLibHandler(void* libHandler);
	void        setWinWidth(int winWidth);
	void        setWinHeight(int winHeight);
    void        setFood(Food* food);

    bool        checkEat();

	~GameEngine();

private:
	GameEngine();
	Snake*      _snake;
    Food*       _food;
	ILibrary*   _library;
    int         _score;
	int         _winWidth;
	int         _winHeight;
	int         _libID;
	void*       _libHandler;
	bool        _libChange;
	bool        _foodAvailable;
	bool        _gameOver;
	bool        _exit;
};

#endif //NIBBLER_GAMEENGINE_HPP
