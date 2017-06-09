//
// Created by Kyle Gani on 2017/06/08.
//

#include "../inc/SDL.hpp"

SDL::SDL(int winWidth, int winHeight, Snake *snake) : _winWidth(winWidth), _winHeight(winHeight), _snake(snake) {
	std::cout << "initialized SDL library at Width: " << _winWidth << " and Height: " << winHeight << std::endl;
	SDL_Init(SDL_INIT_EVERYTHING);
	_window = SDL_CreateWindow("Nibbler - SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _winWidth, _winHeight, SDL_WINDOW_BORDERLESS);
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

int SDL::keyhook() {
	int ret = 1;
	SDL_PollEvent( &this->_windowEvent);
    switch( this->_windowEvent.type ){
        case SDL_KEYDOWN:
            switch(this->_windowEvent.key.keysym.sym) {
                case SDLK_ESCAPE:
                    std::cout << "Escape Key pressed." << std::endl;
                    ret = 0;
                    break;
            }
            break;
        case SDL_QUIT:
            ret = 0;
            std::cout << "Exit signal received" << std::endl;
            break;
        default:
            break;
    }
	return ret;
}

void SDL::print() {
    for(int i = 0 ; i < _snake->getLength(); i++) {
        std::cout << _snake->getParts()[i].getPosX() << std::endl;
        SDL_Rect snakeSquare = {_snake->getParts()[i].getPosX(), _snake->getParts()[i].getPosY(), 10, 10};
        SDL_FillRect(_windowSurface, &snakeSquare, SDL_MapRGB(_windowSurface->format, 0x00, 0x00, 0x00));
    }



}

ILibrary *create(int winWidth, int winHeight, Snake* snake){
	return new SDL(winWidth, winHeight, snake);
}

//TODO Add assignment operator logic for SDL Library
//TODO Add copy constructor logic for SDL Library