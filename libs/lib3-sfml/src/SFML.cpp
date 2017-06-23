//
// Created by Kyle GANI on 2017/06/08.
//

#include "../inc/SFML.hpp"

SFML::SFML(int winHeight, int winWidth) : _window(new sf::RenderWindow), _blockSize(20), _winHeight(winHeight), _winWidth(winWidth)
{
	_window->create(sf::VideoMode(winHeight, winWidth), "Nibbler!", sf::Style::Titlebar | sf::Style::Close);
	_window->setFramerateLimit(60);
	_window->setVerticalSyncEnabled(true);
    _window->isOpen();
	std::cout << "initialized SFML library at Width: " << _winWidth << " and Height: " << _winHeight << std::endl;
}

SFML::~SFML(){
	std::cout << "Dead SFML\n";
}

int SFML::keyhook(){
	int direction = 0;
	sf::Event ev;
	if (_window->pollEvent(ev)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			direction = 4;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			direction = 2;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			direction = 1;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			direction = 3;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			direction = -1;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
            direction = 5;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
            direction = 6;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
            direction = 7;
        }
		if (ev.type == sf::Event::Closed && direction != 0) {
			_window->close();
			direction = -1;
		}
	}
	return direction;
}

void SFML::print(std::vector<SnakePart*> snakeParts, Food* food, std::string score){

	_window->clear();
	sf::RectangleShape _shape(sf::Vector2f(_blockSize, _blockSize));
	sf::RectangleShape _food(sf::Vector2f(_blockSize, _blockSize));

	_food.setPosition(food->getPosX() - 20/2, food->getPosY() - 20/2);
	_food.setSize(sf::Vector2f(_blockSize, _blockSize));
	_food.setFillColor(sf::Color::Red);

	_shape.setSize(sf::Vector2f(_blockSize, _blockSize));
	_shape.setFillColor(sf::Color::Green);

	for (auto i = snakeParts.begin(); i < snakeParts.end(); i++){
		_shape.setPosition((*i)->getPosX() - 20/2 , (*i)->getPosY() + 20/2);
		_window->draw(_shape);
	}
	_window->draw(_food);
	_window->display();
}

ILibrary *create(int winWidth, int winHeight){
	return new SFML(winWidth, winHeight);
}