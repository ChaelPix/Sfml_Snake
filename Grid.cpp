#include "Grid.h"

Grid::Grid(int nbPixels, int pixelSize, int windowSize, sf::Color lineColor)
{
	hline.setSize(sf::Vector2f(windowSize, 1));
	vline.setSize(sf::Vector2f(1, windowSize));

	hline.setFillColor(lineColor);
	vline.setFillColor(lineColor);

	this->nbPixels = nbPixels;
	this->pixelSize = pixelSize;
	this->windowSize = windowSize;

	SetupGrid();
}

void Grid::SetupGrid()
{
	for (int i = 0; i < nbPixels; i++)
	{
		sf::RectangleShape line = hline;
		line.setPosition(sf::Vector2f(0, i * pixelSize));
		grid.push_back(line);

		line = vline;
		line.setPosition(sf::Vector2f(i * pixelSize, 0));
		grid.push_back(line);
	}
}

void Grid::DrawGrid(sf::RenderWindow& window)
{
	for (const auto& line : grid)
		window.draw(line);
}