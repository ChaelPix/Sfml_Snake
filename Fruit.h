#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Fruit
{
private:
	int pixelSize;
	int nbPixels;
	sf::RectangleShape fruitPixel;

public:
	Fruit(int pixelSize, int nbPixels, std::vector<sf::Vector2f> snakePartsPosition);

	sf::RectangleShape getFruit();

	void NewPosition(std::vector<sf::Vector2f> snakePartsPosition);
	sf::Vector2f getPixelPosition();
};

