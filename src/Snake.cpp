//
// Created by Kyle Gani on 2017/06/08.
//
#include "../inc/Snake.hpp"

#define LEFT 1
#define RIGHT 2
int UP = 3;
#define DOWN 4

Snake::Snake() {}
Snake::Snake(int startX, int startY) : _length(4) {
	for (int i = 0; i < 4; i++){
		_parts.push_back(SnakePart(startX, startY--, UP));
	}
}
