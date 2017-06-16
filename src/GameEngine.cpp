//
// Created by Kyle Gani on 2017/06/08.
//

#include "../inc/GameEngine.hpp"

GameEngine::GameEngine(int winWidth, int winHeight, int libID) :
		_winWidth(winWidth),
		_winHeight(winHeight),
		_libID(libID),
        _exit(false)
{
	std::cout << "Game constructed" << std::endl;
	_snake = new Snake(_winWidth / 2, _winHeight / 2);
	_food = new Food(_winWidth, _winHeight, _snake->getParts());
}

GameEngine::~GameEngine() {
	if (_library)
		delete _library;
	if (_snake)
		delete _snake;
	if (_food)
		delete _food;
	std::cout << "Game Destructed." << std::endl;
}

ILibrary* GameEngine::getLibrary() {
	return this->_library;
}

void GameEngine::setLibrary(ILibrary* library) {
	this-> _library = library;
}


void* GameEngine::getLibHandler(){
	return this->_libHandler;
}

void GameEngine::setLibHandler(void *libHandler){
	this-> _libHandler = libHandler;
}

int GameEngine::getWinWidth() {
	return this->_winWidth;
}

void GameEngine::setWinWidth(int winWidth) {
	this->_winWidth = winWidth;
}

int GameEngine::getWinHeight() {
	return this->_winHeight;
}

void GameEngine::setWinHeight(int winHeight) {
	this->_winHeight = winHeight;
}

Snake* GameEngine::getSnake() {
    return this->_snake;
}

Food* GameEngine::getFood() {
	return this->_food;
}

void GameEngine::setFood(Food* food) {
    this->_food = food;
}

bool GameEngine::getExit() {
	return this->_exit;
}

bool GameEngine::checkEat() {
    SnakePart *tmpSnakePart = _snake->getParts()[0];

    if (_food->getPosX() >= tmpSnakePart->getPosX() - (20/2) && _food->getPosX() <= tmpSnakePart->getPosX() + (20/2))
        if (_food->getPosY() >= tmpSnakePart->getPosY() - (20/2) && _food->getPosY() <= tmpSnakePart->getPosY() + (20/2)) {
            std::cout << "Snake ate food." << std::endl;
            return true;
        }
    return false;
}