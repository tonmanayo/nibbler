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
    _direction = 0;
    _tl = 0;
	std::cout << "initialized SFML library at Width: " << _winWidth << " and Height: " << _winHeight << std::endl;
}

SFML::~SFML(){
	std::cout << "Dead SFML\n";
}

int SFML::keyhook(){

	sf::Event ev;
	if (_window->pollEvent(ev)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            _direction = 4;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            _direction = 2;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            _direction = 1;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            _direction = 3;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            _direction = -1;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
            _direction = 5;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
            _direction = 6;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
            _direction = 7;
        }
		if (ev.type == sf::Event::Closed && _direction != 0) {
			_window->close();
            _direction = -1;
		}
	}
	return _direction;
}
void SFML::mvDirec() {
    if (_direction == 2) {
        _tl = 90;
    } else if (_direction == 3) {
        _tl = 180;
    } else if (_direction == 4) {
        _tl = 270;
    } else if (_direction == 1) {
        _tl = 0;
    }
}
void SFML::print(std::vector<SnakePart*> snakeParts, Food* food, std::string score){
	_window->clear();
//score
	sf::Font font;
	if (!font.loadFromFile("/Library/Fonts/Arial.ttf")) {
		std::cout << "Can't laod font\n";
	}

    sf::Text iscore;
	iscore.setFont(font);
    iscore.setString(score);
    iscore.setFillColor(sf::Color::White);
//shapes
    _snakeHead.image.loadFromFile("sprites/head-snake.png");
    _snakeHead.image.createMaskFromColor(sf::Color::White);
    _snakeHead.texture.loadFromImage(_snakeHead.image, sf::IntRect(0, 0, 32, 32));
    _snakeHead.sprite.setTexture(_snakeHead.texture);
    _snakeHead.sprite.setOrigin(16, 16);
    mvDirec();
    _snakeHead.sprite.setRotation(_tl);

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
    _snakeHead.sprite.setPosition(snakeParts[0]->getPosX(), snakeParts[0]->getPosY() + 20);
    _window->draw(_snakeHead.sprite);
	_window->draw(_food);
    _window->draw(iscore);
	_window->display();
}

ILibrary *create(int winWidth, int winHeight){
	return new SFML(winWidth, winHeight);
}