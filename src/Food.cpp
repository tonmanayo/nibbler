//
// Created by Kyle GANI on 2017/06/13.
//

#include "../inc/Food.hpp"



Food::Food(int winWidth, int winHeight, std::vector<SnakePart*> parts): _winWidth(winWidth), _winHeight(winHeight) {
    std::cout << "Initialized food" << std::endl;
    genFood(parts);
}


void Food::genFood(std::vector<SnakePart *> parts) {
    bool onSnake = false;
    int minX = 20;
    int minY = 20;
    int maxX = _winWidth - 20;
    int maxY = _winHeight - 20;

    std::srand(clock());
    _posX = (std::rand() % (maxX-minX + 1) + minX) /20 * 20;
    _posY = (std::rand() % (maxY-minY + 1) + minY) /20 * 20;
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