//
// Created by Kyle Gani on 2017/06/08.
//
#include "../inc/Snake.hpp"

int UP = 1;
int RIGHT = 2;
int DOWN = 3;
int LEFT = 4;

Snake::Snake(int startX, int startY) : _length(4) {
	std::cout << "Creating Snake." << std::endl;
	for (int i = 0; i < 4; i++){
		_parts.push_back(new SnakePart(startX, startY -= 20, UP));
	}
}

Snake::~Snake() {
	std::cout << "Destroying Snake." << std::endl;
}

std::vector<SnakePart*> Snake::getParts() {
	return this->_parts;
}

void Snake::update(int direction) {
	for (int i = _length - 1; i >= 0; i--){
		if (i != 0) {
			_parts[i]->setPosX(_parts[i - 1]->getPosX());
			_parts[i]->setPosY(_parts[i - 1]->getPosY());
			_parts[i]->setDirection(_parts[i - 1]->getDirection());
		} else {
			if (direction)
				_parts[i]->setDirection(direction);
			switch(_parts[i]->getDirection()){
				case 1:
					_parts[i]->setPosY(_parts[i]->getPosY() - 20);
					break;
				case 2:
					_parts[i]->setPosX(_parts[i]->getPosX() + 20);
					break;
				case 3:
					_parts[i]->setPosY(_parts[i]->getPosY() + 20);
					break;
				case 4:
					_parts[i]->setPosX(_parts[i]->getPosX() - 20);
					break;
				default: break;
			}
		}
	}
}

int Snake::getLength() {
	return this->_length;
}

void Snake::setLength(int newLength) {
	this->_length = newLength;
}