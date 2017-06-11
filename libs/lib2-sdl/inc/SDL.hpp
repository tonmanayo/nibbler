//
// Created by Kyle Gani on 2017/06/08.
//

#ifndef NIBBLER_SDL_HPP
#define NIBBLER_SDL_HPP

#include "SDL.h"
#include <iostream>
#include <vector>
#include "../../inc/ILibrary.hpp"

class SDL : public ILibrary {
public:
	SDL(int winWidth, int winHeight);
	SDL(SDL const &sdl);
	SDL &operator=(SDL const &src);
	virtual ~SDL();

	int             keyhook();
	void            print(std::vector<SnakePart*> snakeParts);

private:
	SDL();
	int             _winWidth;
	int             _winHeight;
	SDL_Window*     _window;
	SDL_Renderer*    _windowRenderer;
	SDL_Event      _windowEvent;
};

#ifdef __cplusplus
extern "C" {
#endif

extern "C" ILibrary* create(int winWidth, int WinHeight);

#ifdef __cplusplus
}
#endif


#endif //NIBBLER_SDL_HPP
