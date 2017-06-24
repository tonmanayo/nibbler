//
// Created by Kyle GANI on 2017/06/08.
//

#include "../inc/SFMLv2.hpp"

SFMLv2::SFMLv2(int winHeight, int winWidth) : _window(new sf::RenderWindow), _blockSize(20), _winHeight(winHeight), _winWidth(winWidth)
{
	_window->create(sf::VideoMode(winHeight, winWidth), "Nibbler!", sf::Style::Titlebar | sf::Style::Close);
	_window->setFramerateLimit(60);
	_window->setVerticalSyncEnabled(true);
	_window->isOpen();
	std::cout << "initialized SFMLv2 library at Width: " << _winWidth << " and Height: " << _winHeight << std::endl;
}

SFMLv2::~SFMLv2(){
	std::cout << "Dead SFMLv2\n";
}

int SFMLv2::keyhook(){
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
		}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
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

void SFMLv2::print(std::vector<SnakePart*> snakeParts, Food* food, Bonus* bonus, std::string score){

	_window->clear();
    sf::CircleShape _shape;

    _shape.setRadius(_blockSize / 2);
    _shape.setOutlineColor(sf::Color::Red);
    _shape.setOutlineThickness(3);
	sf::RectangleShape _food(sf::Vector2f(_blockSize, _blockSize));

	_food.setPosition(food->getPosX() - 20/2, food->getPosY() - 20/2);
	_food.setSize(sf::Vector2f(_blockSize, _blockSize));
	_food.setFillColor(sf::Color::Red);
	_shape.setFillColor(sf::Color::Blue);

	for (auto i = snakeParts.begin(); i < snakeParts.end(); i++){
		_shape.setPosition((*i)->getPosX() - 20/2 , (*i)->getPosY() + 20/2);
		_window->draw(_shape);
	}
	_window->draw(_food);
	_window->display();
}

ILibrary *create(int winWidth, int winHeight){
	return new SFMLv2(winWidth, winHeight);
}