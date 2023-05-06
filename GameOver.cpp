#include "GameOver.h"

GameOver::GameOver(int score, sf::RenderWindow &window)
{
	font.loadFromFile(fontName);
	
	gameOverText.setFont(font);
	gameOverText.setFillColor(sf::Color::Red);
	gameOverText.setCharacterSize(50);
	gameOverText.setString("GAME OVER");
	gameOverText.setOrigin(gameOverText.getGlobalBounds().width/2, gameOverText.getGlobalBounds().height/2);
	gameOverText.setPosition(400, 200);

	scoreText = gameOverText;
	scoreText.setFillColor(sf::Color::Black);
	scoreText.setCharacterSize(40);
	scoreText.setString("Score : " + std::to_string(score));
	scoreText.setOrigin(scoreText.getGlobalBounds().width/2, scoreText.getGlobalBounds().height/2);
	scoreText.setPosition(400, 300);

	restartText = scoreText;
	restartText.setCharacterSize(30);
	restartText.setString("[R] to restart");
	restartText.setOrigin(restartText.getGlobalBounds().width/2, restartText.getGlobalBounds().height/2);
	restartText.setPosition(400, 600);
	restartText.setStyle(sf::Text::Italic);

	window.draw(gameOverText);
	window.draw(scoreText);
	window.draw(restartText);
}
