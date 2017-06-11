//
// Created by Kyle Gani on 2017/06/08.
//

#include "../inc/SDL.hpp"

SDL::SDL(int winWidth, int winHeight) : _winWidth(winWidth), _winHeight(winHeight) {
	std::cout << "initialized SDL library at Width: " << _winWidth << " and Height: " << winHeight << std::endl;
	SDL_Init(SDL_INIT_EVERYTHING);
	_window = SDL_CreateWindow("Nibbler - SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _winWidth, _winHeight, SDL_WINDOW_BORDERLESS);
	if (_window == NULL)
		throw std::runtime_error("Could not open SDL window.");
	_windowRenderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED );
	SDL_SetRenderDrawColor(_windowRenderer, 0, 0, 0, 255);
	SDL_RenderClear(_windowRenderer);
	SDL_RenderPresent(_windowRenderer);
}

SDL::~SDL() {
	if (_window)
		SDL_DestroyWindow(_window);
	SDL_Quit();
	std::cout << "Deconstructed SDL library" << std::endl;
}

int SDL::keyhook() {
	int ret = 0;
	SDL_PollEvent( &this->_windowEvent);
    switch( this->_windowEvent.type ){
        case SDL_KEYDOWN:
            switch(this->_windowEvent.key.keysym.sym) {
                case SDLK_ESCAPE:
                    std::cout << "Escape Key pressed." << std::endl;
                    ret = -1;
                    break;
	            case SDLK_UP:
		            std::cout << "Up Key pressed." << std::endl;
		            ret = 1;
		            break;
	            case SDLK_RIGHT:
		            std::cout << "Right Key pressed." << std::endl;
		            ret = 2;
		            break;
	            case SDLK_DOWN:
		            std::cout << "Down Key pressed." << std::endl;
		            ret = 3;
		            break;
	            case SDLK_LEFT:
		            std::cout << "Left Key pressed." << std::endl;
		            ret = 4;
		            break;
            }
            break;
        case SDL_QUIT:
            ret = -1;
            std::cout << "Exit signal received" << std::endl;
            break;
        default:
            break;
    }
	return ret;
}

void SDL::print(std::vector<SnakePart*> snakeParts) {
	SDL_SetRenderDrawColor(_windowRenderer, 0, 0, 0, 255);
	SDL_RenderClear(_windowRenderer);
	SDL_SetRenderDrawColor(_windowRenderer, 255, 255, 255, 255);
	for (auto i = snakeParts.begin(); i < snakeParts.end(); i++){
		SDL_Rect snakeRect= {(*i)->getPosX() - 20/2, (*i)->getPosY() + 20/2, 20, 20};
		SDL_RenderFillRect(_windowRenderer, &snakeRect );
	}
	SDL_RenderPresent(_windowRenderer);
}

ILibrary *create(int winWidth, int winHeight){
	return new SDL(winWidth, winHeight);
}

//TODO Add assignment operator logic for SDL Library
//TODO Add copy constructor logic for SDL Library