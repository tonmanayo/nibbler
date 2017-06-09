//
// Created by Kyle Gani on 2017/06/08.
//

#ifndef NIBBLER_SDL_HPP
#define NIBBLER_SDL_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include "../../inc/ILibrary.hpp"

class SDL : public ILibrary {
public:
	SDL(int winWidth, int winHeight);
	SDL(SDL const &sdl);
	SDL &operator=(SDL const &src);
	virtual ~SDL();

	void        keyhook();
	void        print();

private:
	SDL();
	int         _winWidth;
	int         _winHeight;
	SDL_Window*     _window;
	SDL_Surface*    _windowSurface;
};

#ifdef __cplusplus
extern "C" {
#endif

extern "C" ILibrary* create(int winWidth, int WinHeight);

#ifdef __cplusplus
}
#endif


#endif //NIBBLER_SDL_HPP
