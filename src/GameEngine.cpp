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
	_snake = new Snake(_winHeight / 2, winWidth / 2);
}

GameEngine::~GameEngine() {
	if (_library)
		delete _library;
	delete _snake;
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

bool GameEngine::getExit() {
	return this->_exit;
}