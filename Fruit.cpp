#include "Fruit.h"

Fruit::Fruit(int pixelSize, int nbPixels, std::vector<sf::Vector2f> snakePartsPosition)
{
	this->pixelSize = pixelSize;
	this->nbPixels = nbPixels;

	fruitPixel.setSize(sf::Vector2f(pixelSize, pixelSize));
	fruitPixel.setFillColor(sf::Color::Red);

	NewPosition(snakePartsPosition);
}

void Fruit::NewPosition(std::vector<sf::Vector2f> snakePartsPosition)
{
	bool isPlaced = false;
	sf::Vector2f position;

	while (!isPlaced)
	{
		position = sf::Vector2f(rand() % nbPixels, rand() % nbPixels);

		isPlaced = true;

		for (const auto& snake : snakePartsPosition)
			isPlaced = !(position == snake);

	}

	fruitPixel.setPosition(sf::Vector2f(position.x * pixelSize, position.y * pixelSize));

}

sf::RectangleShape Fruit::getFruit()
{
	return fruitPixel;
}

sf::Vector2f Fruit::getPixelPosition()
{
	sf::Vector2f pos = fruitPixel.getPosition();
	pos = sf::Vector2f(pos.x / pixelSize, pos.y / pixelSize);
	return pos;
}