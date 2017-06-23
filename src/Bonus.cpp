//
// Created by Tony MACK on 2017/06/23.
//

#include "../inc/Bonus.hpp"

Bonus::Bonus(int winWidth, int winHeight, std::vector<SnakePart*> parts): _winWidth(winWidth), _winHeight(winHeight) {
    std::cout << "Initialized Bonus" << std::endl;
    genBonus(parts);
}


void Bonus::genBonus(std::vector<SnakePart *> parts) {

    bool onSnake = false;
    int minX = 20;
    int minY = 20;
    int maxX = _winWidth - 20;
    int maxY = _winHeight - 20;

    seconds = time(NULL);
    std::srand(time(NULL));
    _posX = (std::rand() % (maxX-minX + 1) + minX) /20 * 20;
    _posY = (std::rand() % (maxY-minY + 1) + minY) /20 * 20;
    for (auto it = parts.begin(); it < parts.end(); it++){
        if (_posX == (*it)->getPosX() && _posY == (*it)->getPosY())
            onSnake = true;
    }
    if (onSnake && (seconds % 15) == 0)
        genBonus(parts);
    else
        std::cout << "Bonus generated at X: " << _posX << " Y: " << _posY << std::endl;
}

int Bonus::getPosX() {
    return this->_posX;
}

int Bonus::getPosY() {
    return this->_posY;
}

Bonus::~Bonus() {
    std::cout << "Destroyed Bonus" << std::endl;
}