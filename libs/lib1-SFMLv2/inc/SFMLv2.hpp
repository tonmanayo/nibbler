//
// Created by Kyle GANI on 2017/06/08.
//sudo apt-get install libSFMLv2-dev

#ifndef NIBBLER_SFMLv2_HPP
#define NIBBLER_SFMLv2_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <memory>
#include "../../inc/ILibrary.hpp"

typedef std::shared_ptr<sf::RenderWindow> RenderWindowPtr;

class SFMLv2 : public ILibrary {
public:
	SFMLv2(int winWidth, int winHeight);
	SFMLv2(SFMLv2 const &rhs);
	SFMLv2 operator=(SFMLv2 const &rhs );
	virtual ~SFMLv2();

	int keyhook();
	void print(std::vector<SnakePart*> snakeParts, Food* food, Bonus* bonus, std::string score);

private:
	SFMLv2();
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

#endif //NIBBLER_SFMLv2_HPP
