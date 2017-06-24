//
// Created by Kyle GANI on 2017/06/13.
//

#include "../inc/Food.hpp"

Food::Food(int winWidth, int winHeight, std::vector<SnakePart*> parts, int squareSize):
        _winWidth(winWidth),
        _winHeight(winHeight),
        _squareSize(squareSize)
{
    std::cout << "Initialized food" << std::endl;
    genFood(parts);
}


void Food::genFood(std::vector<SnakePart *> parts) {
    bool onSnake = false;
    int minX = _squareSize;
    int minY = _squareSize;
    int maxX = _winWidth - _squareSize;
    int maxY = _winHeight - _squareSize;

    std::srand(clock());
    _posX = (std::rand() % (maxX-minX + 1) + minX) /_squareSize * _squareSize;
    _posY = (std::rand() % (maxY-minY + 1) + minY) /_squareSize * _squareSize;
    for (auto it = parts.begin(); it < parts.end(); it++){
        if (_posX == (*it)->getPosX() && _posY == (*it)->getPosY())
            onSnake = true;
    }
    if (onSnake)
        genFood(parts);
    else
        std::cout << "Food generated at X: " << _posX << " Y: " << _posY << std::endl;
}

int Food::getPosX() {
    return this->_posX;
}

int Food::getPosY() {
    return this->_posY;
}

Food::~Food() {
    std::cout << "Destroyed food" << std::endl;
}