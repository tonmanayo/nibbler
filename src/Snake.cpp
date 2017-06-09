//
// Created by Kyle Gani on 2017/06/08.
//
#include "../inc/Snake.hpp"

#define LEFT 1
#define RIGHT 2
int UP = 3;
#define DOWN 4

Snake::Snake(int startX, int startY) : _length(4) {
	std::cout << "Creating Snake." << std::endl;
	for (int i = 0; i < 4; i++){
		_parts.push_back(SnakePart(startX, startY--, UP));
	}
}

Snake::~Snake() {
	std::cout << "Destroying Snake." << std::endl;
}

std::vector<SnakePart> Snake::getParts() {
	return this->_parts;
}

int Snake::getLength() {
	return this->_length;
}

void Snake::setLength(int newLength) {
	this->_length = newLength;
}