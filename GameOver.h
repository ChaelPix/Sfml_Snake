#pragma once
#include <SFML/Graphics.hpp>

class GameOver
{
private :
	std::string fontName = "Ressources/Ubuntu.ttf";
	sf::Font font;
	sf::Text gameOverText;
	sf::Text scoreText;
	sf::Text restartText;

	sf::Vector2f position;
public :
	GameOver(int score, sf::RenderWindow &window);
};

