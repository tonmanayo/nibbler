//
// Created by Kyle GANI on 2017/06/08.
//sudo apt-get install libsfml-dev

#ifndef NIBBLER_SFML_HPP
#define NIBBLER_SFML_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <memory>
#include "../../inc/ILibrary.hpp"

typedef std::shared_ptr<sf::RenderWindow> RenderWindowPtr;

typedef struct		s_spriteStr
{
	sf::Texture	texture;
	sf::Image	image;
	sf::Sprite	sprite;
}					t_spriteStr;

class SFML : public ILibrary {
public:
	SFML(int winWidth, int winHeight);
	SFML(SFML const &rhs);
	SFML operator=(SFML const &rhs );
	virtual ~SFML();
    void mvDirec();


        int keyhook();
	void print(std::vector<SnakePart*> snakeParts, Food* food, Bonus* bonus, std::string score);

private:
	SFML();
	const unsigned int _winWidth;
	const unsigned int _winHeight;
	const unsigned int _blockSize;
	RenderWindowPtr _window;
	t_spriteStr _snakeHead;
    t_spriteStr _popcorn;

    int _direction;
    int _tl;
    sf::SoundBuffer _sbuffer;
    sf::Sound _sound;
};


#ifdef __cplusplus
extern "C" {
#endif

ILibrary* create(int winWidth, int winHeight);

#ifdef __cplusplus
}
#endif

#endif //NIBBLER_SFML_HPP
