//
// Created by Kyle Gani on 2017/06/08.
//

#include "../inc/SDL.hpp"

SDL::SDL() {
	std::cout << "initialized SDL library without parameters" << std::endl;
}

SDL::SDL(int winWidth, int winHeight) : _winWidth(winWidth), _winHeight(winHeight) {
	std::cout << "initialized SDL library with parameters" << std::endl;
}

SDL::~SDL() {
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