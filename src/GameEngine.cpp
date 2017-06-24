//
// Created by Kyle Gani on 2017/06/08.
//

#include "../inc/GameEngine.hpp"

GameEngine::GameEngine(int winWidth, int winHeight, int libID, int squareSize) :
        _score(0),
		_winWidth(winWidth),
		_winHeight(winHeight),
        _libID(libID),
        _squareSize(squareSize),
        _exit(false)
{
	std::cout << "Game constructed" << std::endl;
	_snake = new Snake(_winWidth / 2, _winHeight / 2, _squareSize);
	_food = new Food(_winWidth, _winHeight, _snake->getParts(), _squareSize);
	_bonus = new Bonus(_winWidth, _winHeight, _snake->getParts());
}

GameEngine::~GameEngine() {
	if (_library)
		delete _library;
	if (_snake)
		delete _snake;
	if (_food)
		delete _food;
	if (_bonus)
		delete _bonus;
	std::cout << "Game Destructed." << std::endl;
}

ILibrary* GameEngine::getLibrary() {
	return this->_library;
}

void GameEngine::setLibrary(ILibrary* library) {
	this-> _library = library;
}

void GameEngine::destroyLib() {

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

void GameEngine::addScore(int newScore) {
    _score += newScore;
}

Snake* GameEngine::getSnake() {
    return this->_snake;
}

Food* GameEngine::getFood() {
	return this->_food;
}

Bonus* GameEngine::getBonus() {
	return this->_bonus;
}

void GameEngine::setFood(Food *food) {
    this->_food = food;
}

void GameEngine::setBonus(Bonus *bonus){
	this->_bonus = bonus;
}

bool GameEngine::getExit() {
	return this->_exit;
}

int GameEngine::getScore() {
	return this->_score;
}

int GameEngine::getLibId() {
	return this->_libID;
}

void GameEngine::setLibId(int newLibId) {
	this->_libID = newLibId;
}

int GameEngine::getSquareSize() {
    return this->_squareSize;
}

bool GameEngine::checkEat() {
    SnakePart *tmpSnakePart = _snake->getParts()[0];
    if (_food->getPosX() == tmpSnakePart->getPosX())
        if (_food->getPosY() == tmpSnakePart->getPosY() + 20) {
            std::cout << "Snake ate food." << std::endl;
            return true;
        }
    return false;
}

bool GameEngine::checkBonus(){
	SnakePart *tmpSnakePart = _snake->getParts()[0];
	if (_bonus->getPosX() == tmpSnakePart->getPosX())
		if (_bonus->getPosY() == tmpSnakePart->getPosY() + 20) {
			std::cout << "Snake ate bonus." << std::endl;
			return true;
		}
	return false;
}