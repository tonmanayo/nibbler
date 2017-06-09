//
// Created by Kyle Gani on 2017/06/08.
//

#include "SnakePart.hpp"

SnakePart::SnakePart(SnakePart const &snakePart) {
	*this = snakePart;
}

SnakePart::~SnakePart() {
}

SnakePart::SnakePart(int posX, int posY, int direction) :
	_posX(posX),
    _posY(posY),
    _direction(direction)
{
	std::cout << "Snake part created at X: " << _posX << " Y: " << _posY << std::endl;
}

SnakePart& SnakePart::operator=(SnakePart const &src) {
	if (this != &src){

	}
	return *this;
}
