//
// Created by Tony MACK on 2017/06/23.
//

#ifndef NIBBLER_BONUS_HPP
#define NIBBLER_BONUS_HPP

#include <vector>
#include "SnakePart.hpp"
#include <time.h>

class Bonus {
public:
    Bonus(int winWidth, int winHeight, std::vector<SnakePart*> parts);
    Bonus(Bonus const &Bonus);
    Bonus &operator=(Bonus const &src);
    virtual ~Bonus();

    void update();
    void genBonus(std::vector<SnakePart*> parts);

    int getPosX();
    int getPosY();
private:
    Bonus();
    int _winWidth;
    int _winHeight;
    int _posX;
    int _posY;
    time_t timer;
    int seconds;
};

#endif //NIBBLER_BONUS_HPP
