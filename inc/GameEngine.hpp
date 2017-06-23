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
	GameEngine(int winWidth, int winHeight, int libId, int squareSize);
	GameEngine &operator=(GameEngine const &src);

	ILibrary*   getLibrary();
	void*       getLibHandler();
	int         getWinWidth();
	int         getWinHeight();
    Snake*      getSnake();
    Food*       getFood();
	bool        getExit();
	int         getScore();
	int			getLibId();
    int         getSquareSize();

	void        setLibrary(ILibrary* library);
	void        setLibHandler(void* libHandler);
	void        setWinWidth(int winWidth);
	void        setWinHeight(int winHeight);
    void        setFood(Food* food);
	void		setLibId(int newLibId);
    void        destroyLib();

    bool        checkEat();
    void        addScore(int newScore);

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
    int         _squareSize;
	void*       _libHandler;
	bool        _libChange;
	bool        _foodAvailable;
	bool        _gameOver;
	bool        _exit;
};

#endif //NIBBLER_GAMEENGINE_HPP
