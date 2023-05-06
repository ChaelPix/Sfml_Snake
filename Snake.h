#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Fruit.h"
#include "SoundEffect.h"

class Snake
{
private :

	SoundEffect pickupSfx;

	enum Direction { Left, Right, Up, Bottom };
	float speed = 1;

	std::map<Direction, sf::Vector2f> directionMap = {
	{Direction::Left, sf::Vector2f(-speed, 0)},
	{Direction::Right, sf::Vector2f(speed, 0)},
	{Direction::Up, sf::Vector2f(0, -speed)},
	{Direction::Bottom, sf::Vector2f(0, speed)}
	};

	int pixelSize;
	int nbPixels;

	std::vector<sf::Vector2f> snakePartsPosition;

	sf::RectangleShape snakePixel;

	
	Direction actualDirection = Direction::Left;

	void ListenMoveInput();

	void ChangeSnakeDirection(Direction direction);

	void ExtendSnake();

	void CreateNewSnake();

public :

	Snake(int pixelSize, int nbPixels);

	bool update(sf::RenderWindow& window, Fruit& fruit);

	std::vector<sf::Vector2f> getSnakePartsPosition();

	void Reset();
};

