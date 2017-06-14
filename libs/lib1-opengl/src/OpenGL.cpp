//
// Created by Kyle GANI on 2017/06/08.
//
#include "../inc/OpenGL.hpp"


OpenGL::OpenGL(int winWidth, int winHeight) : _winWidth(winWidth), _winHeight(winHeight), _blockSize(20), _FPS(22) {
    std::cout << "initialized OpenGL library at Width: " << _winWidth << " and Height: " << _winHeight << std::endl;
	_redraw = true;
	if(!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return ;
	}

	if(!al_install_keyboard()) {
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return ;
	}

//	_timer = al_create_timer(1.0 / _FPS);
//	if(!_timer) {
//		fprintf(stderr, "failed to create timer!\n");
//		return ;
//	}

	_display = al_create_display(_winWidth, _winHeight);
	if(!_display) {
		fprintf(stderr, "failed to create display!\n");
//		al_destroy_timer(_timer);
		return ;
	}

	_box = al_create_bitmap(_blockSize, _blockSize);
	if(!_box) {
		fprintf(stderr, "failed to create box bitmap!\n");
		al_destroy_display(_display);
	//	al_destroy_timer(_timer);
		return ;
	}

	al_set_target_bitmap(_box);
	al_clear_to_color(al_map_rgb(255, 0, 255));
	al_set_target_bitmap(al_get_backbuffer(_display));

	_event_queue = al_create_event_queue();
	if(!_event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_bitmap(_box);
		al_destroy_display(_display);
	//	al_destroy_timer(_timer);
		return ;
	}

	al_register_event_source(_event_queue, al_get_display_event_source(_display));
//	al_register_event_source(_event_queue, al_get_timer_event_source(_timer));
	al_register_event_source(_event_queue, al_get_keyboard_event_source());
	al_clear_to_color(al_map_rgb(0,0,0));
	al_flip_display();
//	al_start_timer(_timer);
}

OpenGL::~OpenGL(){
	al_destroy_bitmap(_box);
//	al_destroy_timer(_timer);
	al_destroy_display(_display);
	al_destroy_event_queue(_event_queue);
}

int OpenGL::keyhook(){
	ALLEGRO_EVENT ev;
	al_get_next_event(_event_queue, &ev);
	if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch(ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				return  1;
			case ALLEGRO_KEY_RIGHT:
				return 2;
			case ALLEGRO_KEY_DOWN:
				return 3;
			case ALLEGRO_KEY_LEFT:
				return 4;
			case ALLEGRO_KEY_ESCAPE:
				return -1;
			default:
				return 0;
		}
	}
	return 0;
}

void OpenGL::print(std::vector<SnakePart*> snakeParts){
	//if(_redraw && al_is_event_queue_empty(_event_queue)) {
	//	_redraw = false;
		al_clear_to_color(al_map_rgb(0,0,0));
		for (auto i = snakeParts.begin(); i < snakeParts.end(); i++){
			al_draw_bitmap(_box, (*i)->getPosX() - 20/2 , (*i)->getPosY() + - 20/2 , 0);
		}
		al_flip_display();
	//}
}

ILibrary *create(int winWidth, int winHeight){
	return new OpenGL(winWidth, winHeight);
}



//g++ -Wall main.cpp -I/usr/include/allegro5 -L/usr/lib -lallegro -lallegro_image -lallegro_primitives
//g++ -Wall main.cpp -I/nfs/zfs-student-6/users/tmack/.brew/Cellar/allegro/5.2.2/include -L/nfs/zfs-student-6/users/tmack/.brew/Cellar/allegro/5.2.2/lib -lallegro -lallegro_image -lallegro_primitives
