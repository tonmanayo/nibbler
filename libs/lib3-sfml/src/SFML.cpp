//
// Created by Kyle GANI on 2017/06/08.
//

#include "../inc/SFML.hpp"

SFML::SFML(int winWidth, int winHeight) : _winWidth(winWidth), _winHeight(winHeight), _window(sf::VideoMode(200, 200), "Nibbler!") ,_blockSize(20)
{
	std::cout << "initialized SFML library at Width: " << _winWidth << " and Height: " << _winHeight << std::endl;
}

SFML::~SFML(){
	std::cout << "Dead SFML\n";
}

int SFML::keyhook(){

	//int direction = 0;
	sf::Event ev;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		return 4;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		return 2;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		return 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		return 3;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		return -1;
	}
	if (ev.type == sf::Event::Closed){
		_window.close();
		return -1;
	}
	return 0;
}

void SFML::print(std::vector<SnakePart*> snakeParts){
	sf::RectangleShape _shape(sf::Vector2f(_blockSize, _blockSize));
	_shape.setPosition(_winHeight / 2,_winWidth / 2);
	_shape.setFillColor(sf::Color::Green);
	for (auto i = snakeParts.begin(); i < snakeParts.end(); i++){
		_shape.setPosition((*i)->getPosX() - 20/2,(*i)->getPosY() + - 20/2);
		_window.clear();
		_window.draw(_shape);
	}
	_window.display();
}