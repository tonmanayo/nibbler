//
// Created by Kyle Gani on 2017/06/08.
//

#ifndef NIBBLER_SDL_HPP
#define NIBBLER_SDL_HPP

#include "SDL.h"
#include <iostream>
#include "../../inc/ILibrary.hpp"

class SDL : public ILibrary {
public:
	SDL(int winWidth, int winHeight, Snake* snake);
	SDL(SDL const &sdl);
	SDL &operator=(SDL const &src);
	virtual ~SDL();

	int             keyhook();
	void            print();

private:
	SDL();
	int             _winWidth;
	int             _winHeight;
    Snake*          _snake;
	SDL_Window*     _window;
	SDL_Surface*    _windowSurface;
	SDL_Event      _windowEvent;
};

#ifdef __cplusplus
extern "C" {
#endif

extern "C" ILibrary* create(int winWidth, int WinHeight, Snake* snake);

#ifdef __cplusplus
}
#endif


#endif //NIBBLER_SDL_HPP
