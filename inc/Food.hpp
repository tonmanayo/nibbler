//
// Created by Kyle GANI on 2017/06/13.
//

#ifndef NIBBLER_FOOD_HPP
#define NIBBLER_FOOD_HPP

#include <vector>
#include "SnakePart.hpp"

class Food {
public:
    Food(int winWidth, int winHeight, std::vector<SnakePart*> parts, int squareSpace);
    Food(Food const &food);
    Food &operator=(Food const &src);
    virtual ~Food();

    void update();
    void genFood(std::vector<SnakePart*> parts);

    int getPosX();
    int getPosY();
private:
    Food();
    int _winWidth;
    int _winHeight;
    int _posX;
    int _posY;
    int _squareSize;
};


#endif //NIBBLER_FOOD_HPP
