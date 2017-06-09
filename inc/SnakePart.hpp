//
// Created by Kyle Gani on 2017/06/08.
//

#ifndef NIBBLER_SNAKEPART_HPP
#define NIBBLER_SNAKEPART_HPP

#include <iostream>

class SnakePart {
public:
	SnakePart(int posX, int posY, int direction);
	SnakePart(SnakePart const &snakePart);
	SnakePart &operator=(SnakePart const &src);

	int getPosX();
	int getPosY();

	~SnakePart();
private:
	SnakePart();
	int _posX;
	int _posY;
	int _direction;
};


#endif //NIBBLER_SNAKEPART_HPP
