#pragma once
#include <SFML/Graphics.hpp>

class Grid
{
private: 
	sf::RectangleShape hline;
	sf::RectangleShape vline;

	std::vector<sf::RectangleShape> grid;

	int nbPixels, pixelSize, windowSize;

	void SetupGrid();

public :
	Grid(int nbPixels, int pixelSize, int windowSize, sf::Color lineColor);

	void DrawGrid(sf::RenderWindow& window);
};

