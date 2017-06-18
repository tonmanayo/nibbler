//
// Created by Kyle GANI on 2017/06/08.
//sudo apt-get install libsfml-dev

#ifndef NIBBLER_SFML_HPP
#define NIBBLER_SFML_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <memory>
#include "../../inc/ILibrary.hpp"

typedef std::shared_ptr<sf::RenderWindow> RenderWindowPtr;

class SFML : public ILibrary {
public:
	SFML(int winWidth, int winHeight);
	SFML(SFML const &rhs);
	SFML operator=(SFML const &rhs );
	virtual ~SFML();

	int keyhook();
	void print(std::vector<SnakePart*> snakeParts, Food* food, std::string score);

private:
	SFML();
	const unsigned int _winWidth;
	const unsigned int _winHeight;
	const unsigned int _blockSize;
	RenderWindowPtr _window;
};


#ifdef __cplusplus
extern "C" {
#endif

ILibrary* create(int winWidth, int winHeight);

#ifdef __cplusplus
}
#endif

#endif //NIBBLER_SFML_HPP
