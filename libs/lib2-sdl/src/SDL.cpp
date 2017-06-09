//
// Created by Kyle Gani on 2017/06/08.
//

#include "../inc/SDL.hpp"

SDL::SDL(int winWidth, int winHeight) : _winWidth(winWidth), _winHeight(winHeight) {
	std::cout << "initialized SDL library at Width: " << _winWidth << " and Height: " << winHeight << std::endl;
	SDL_Init(SDL_INIT_VIDEO);
	_window = SDL_CreateWindow("Nibbler - SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _winWidth, _winHeight, SDL_WINDOW_OPENGL);
	if (_window == NULL)
		throw std::runtime_error("Could not open SDL window.");
	_windowSurface = SDL_GetWindowSurface( _window );
	SDL_FillRect( _windowSurface, NULL, SDL_MapRGB( _windowSurface->format, 0xFF, 0xFF, 0xFF ) );
	SDL_UpdateWindowSurface( _window );
	SDL_Delay( 2000 );
}

SDL::~SDL() {
	if (_window)
		SDL_DestroyWindow(_window);
	SDL_Quit();
	std::cout << "Deconstructed SDL library" << std::endl;
}

ILibrary *create(int winWidth, int winHeight){
	return new SDL(winWidth, winHeight);
}

void destroy(ILibrary *library){
	delete library;
}

void SDL::keyhook() {
	return ;
}

void SDL::print() {

}

//TODO Add assignment operator logic for SDL Library
//TODO Add copy constructor logic for SDL Library