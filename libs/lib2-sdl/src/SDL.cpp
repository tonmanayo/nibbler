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
	initText();
}

SDL::~SDL() {
	TTF_CloseFont(_font);
	TTF_Quit();
    SDL_DestroyTexture(_textTexture);
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
                    ret = -1;
                    break;
	            case SDLK_UP:
		            ret = 1;
		            break;
	            case SDLK_RIGHT:
		            ret = 2;
		            break;
	            case SDLK_DOWN:
		            ret = 3;
		            break;
	            case SDLK_LEFT:
		            ret = 4;
		            break;
				case SDLK_1:
					ret = 5;
					break;
				case SDLK_2:
					ret = 6;
					break;
				case SDLK_3:
					ret = 7;
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

void SDL::print(std::vector<SnakePart*> snakeParts, Food* food, Bonus* bonus, std::string score) {
	SDL_Rect textRect;
	SDL_Color textColor = {255,255,255};
    SDL_SetRenderDrawColor(_windowRenderer, 0, 0, 0, 255);
	SDL_RenderClear(_windowRenderer);
	SDL_SetRenderDrawColor(_windowRenderer, 255, 255, 255, 255);
    _textSurface = TTF_RenderText_Blended(_font, score.c_str(), textColor);
	if (!_textSurface)
		throw std::runtime_error("Failed to create text Surface.");
    _textTexture = SDL_CreateTextureFromSurface(_windowRenderer, _textSurface);
	SDL_FreeSurface(_textSurface);
	SDL_QueryTexture( _textTexture, NULL, NULL, &textRect.w, &textRect.h );
	textRect.x = 30;
	textRect.y = 30;
	for (auto i = snakeParts.begin(); i < snakeParts.end(); i++){
		SDL_Rect snakeRect= {(*i)->getPosX() - 20/2, (*i)->getPosY() + 20/2, 20, 20};
		SDL_RenderFillRect(_windowRenderer, &snakeRect );
	}
	SDL_RenderCopy( _windowRenderer, _textTexture, nullptr, &textRect );
	SDL_Rect foodRect = {food->getPosX() - 20/2, food->getPosY() - 20/2, 20, 20};
	SDL_RenderFillRect(_windowRenderer, &foodRect );
	SDL_RenderPresent(_windowRenderer);
}

void SDL::initText() {
	if (TTF_Init() == -1 )
		throw std::runtime_error("Failed to initialize TTF.");
    _font = TTF_OpenFont( "/Library/Fonts/Arial.ttf", 30 );
	if ( _font == nullptr )
		throw std::runtime_error("Failed to load font.");
}

ILibrary *create(int winWidth, int winHeight){
	return new SDL(winWidth, winHeight);
}

//TODO Add assignment operator logic for SDL Library
//TODO Add copy constructor logic for SDL Library