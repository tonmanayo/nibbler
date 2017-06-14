//
// Created by Kyle GANI on 2017/06/08.
//

#include "../inc/SFML.hpp"

SFML::SFML(int winHeight, int winWidth) : _blockSize(20), _winHeight(winHeight), _winWidth(winWidth)
{
	_window = RenderWindowPtr(new sf::RenderWindow);

	_window->create(sf::VideoMode(winWidth, winHeight), "Nibbler!", sf::Style::Titlebar | sf::Style::Close);
	_window->setFramerateLimit(60);
	_window->setVerticalSyncEnabled(true);
	std::cout << "initialized SFML library at Width: " << _winWidth << " and Height: " << _winHeight << std::endl;
}

SFML::~SFML(){
	std::cout << "Dead SFML\n";
}

int SFML::keyhook(){
	int direction = 0;
	sf::Event ev;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		direction = 4;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		direction = 2;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		direction = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		direction = 3;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		direction = -1;
	}
	if (ev.type == sf::Event::Closed){
		_window->close();
		direction = -1;
	}
	return direction;
}

void SFML::print(std::vector<SnakePart*> snakeParts){



	_window->clear();

	sf::RectangleShape _shape(sf::Vector2f(_blockSize, _blockSize));

	_shape.setPosition(_winHeight / 2,_winWidth / 2);
	_shape.setSize(sf::Vector2f(_blockSize, _blockSize));
	_shape.setFillColor(sf::Color::Green);

	for (auto i = snakeParts.begin(); i < snakeParts.end(); i++){
		//_shape.move((*i)->getPosX() - _blockSize/2,(*i)->getPosY() + - _blockSize/2);
		_shape.setPosition((*i)->getPosX() , (*i)->getPosY() );
		_window->draw(_shape);
	}
	_window->display();

}

ILibrary *create(int winWidth, int winHeight){
	return new SFML(winWidth, winHeight);
}