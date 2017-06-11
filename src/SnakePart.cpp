//
// Created by Kyle Gani on 2017/06/08.
//

#include "SnakePart.hpp"

SnakePart::SnakePart(SnakePart const &snakePart) {
	*this = snakePart;
}

SnakePart::~SnakePart() {
}

SnakePart::SnakePart(int posX, int posY, int direction) {
	this->_posX = posX;
	this->_posY = posY;
	this->_direction = direction;
	std::cout << "Snake part created at X: " << _posX << " Y: " << _posY << std::endl;
}

SnakePart& SnakePart::operator=(SnakePart const &src) {
	if (this != &src){

	}
	return *this;
}

int SnakePart::getPosX() const {
	return this->_posX;
}

void SnakePart::setPosX(int newPosX) {
	this->_posX = newPosX;
}

int SnakePart::getPosY() const {
	return this->_posY;
}

void SnakePart::setPosY(int newPosY) {
	this->_posY = newPosY;
}

int SnakePart::getDirection() const {
	return this->_direction;
}

void SnakePart::setDirection(int newDirection) {
	this->_direction = newDirection;
}
