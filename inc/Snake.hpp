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

	std::vector<SnakePart*>  	getParts();
	int                     	getLength();

	void        				setLength(int newLength);

	void 						update(int direction);
	int  						detectCollision(int winWidth, int winHeight);
	void						addPart();

	~Snake();
private:
	Snake();
	std::vector<SnakePart*>  	_parts;
	int                     	_length;
};


#endif //NIBBLER_SNAKE_HPP
