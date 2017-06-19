//
// Created by Kyle GANI on 2017/06/08.
//

#ifndef NIBBLER_OPENGL_HPP
#define NIBBLER_OPENGL_HPP

#include "allegro5/allegro.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include "../../inc/ILibrary.hpp"
#include <dlfcn.h>


class OpenGL : public ILibrary {
public:
	OpenGL(int winWidth, int winHeight);
	OpenGL(OpenGL const &openGL);
	OpenGL operator=(OpenGL const &rhs );
	virtual ~OpenGL();
	int keyhook();
	void print(std::vector<SnakePart*> snakeParts, Food* food, std::string score);


private:
	OpenGL();
	const unsigned int _winWidth;
	const unsigned int _winHeight;
	const unsigned int _blockSize;
	const unsigned int _FPS;
	ALLEGRO_DISPLAY     *_display;
	ALLEGRO_EVENT_QUEUE *_event_queue;
	ALLEGRO_TIMER       *_timer;
	ALLEGRO_BITMAP      *_box;
};

#ifdef __cplusplus
extern "C" {
#endif

ILibrary* create(int winWidth, int winHeight);

#ifdef __cplusplus
}
#endif

#endif //NIBBLER_OPENGL_HPP
