//
// Created by Kyle Gani on 2017/06/08.
//

#ifndef NIBBLER_SDL_HPP
#define NIBBLER_SDL_HPP

#include "SDL.h"
#include "SDL_ttf.h"
#include <iostream>
#include <vector>
#include "../../inc/ILibrary.hpp"
#include "Food.hpp"


class SDL : public ILibrary {
public:
	SDL(int winWidth, int winHeight);
	SDL(SDL const &sdl);
	SDL &operator=(SDL const &src);
	virtual ~SDL();

	int             keyhook();
	void            print(std::vector<SnakePart*> snakeParts, Food* food, std::string score);
	void			initText();

private:
	SDL();
	int             _winWidth;
	int             _winHeight;
	SDL_Window*     _window;
	SDL_Renderer*   _windowRenderer;
	SDL_Texture*	_textTexture;
	SDL_Surface* 	_textSurface;
	TTF_Font*		_font;
	SDL_Event      	_windowEvent;
};

#ifdef __cplusplus
extern "C" {
#endif

ILibrary* create(int winWidth, int winHeight);

#ifdef __cplusplus
}
#endif

#endif //NIBBLER_SDL_HPP
