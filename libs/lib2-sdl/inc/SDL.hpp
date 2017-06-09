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
	SDL();
	SDL(int winWidth, int winHeight);
	virtual ~SDL();

	void        keyhook();
	void        print();

private:
	int         _winWidth;
	int         _winHeight;
	SDL_Window* _window;
};

#ifdef __cplusplus
extern "C" {
#endif

extern "C" ILibrary* create(int winWidth, int WinHeight);

#ifdef __cplusplus
}
#endif


#endif //NIBBLER_SDL_HPP
