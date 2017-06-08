//
// Created by Kyle Gani on 2017/06/08.
//

#ifndef NIBBLER_SNAKE_HPP
#define NIBBLER_SNAKE_HPP

#include <vector>
#include "SnakePart.hpp"
#include "iostream"

class Snake {
public:
	Snake(int startX, int startY);
	Snake(Snake const &snake);
	Snake &operator=(Snake const &src);

	void growSnake();

	~Snake();
private:
	Snake();
	std::vector<SnakePart>  _parts;
	int                     _length;
};


#endif //NIBBLER_SNAKE_HPP
