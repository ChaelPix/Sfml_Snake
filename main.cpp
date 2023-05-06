#include <SFML/Graphics.hpp>

#include "Snake.h"
#include "Fruit.h"
#include "GameOver.h"
#include "Grid.h"

/*----Settings-----*/
const int squareSize = 800;
const int nbPixels = 40;
const int fps = 15;
sf::Color bgColor = sf::Color::White;
sf::Color lineColor = sf::Color(75, 75, 75, 75);
/*----------------*/

int main()
{
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(squareSize, squareSize), "Snake (2h Challenge)");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(fps);

    sf::Image icon;
    icon.loadFromFile("Ressources/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    int pixelSize = squareSize / nbPixels;
    
    Snake snake(pixelSize, nbPixels);
    Fruit fruit(pixelSize, nbPixels, snake.getSnakePartsPosition());
    Grid grid(nbPixels, pixelSize, squareSize, lineColor);

    SoundEffect gameOverSfx;
    gameOverSfx.Initialize("gameover.wav");
    
    sf::Event event;
    bool isOver = false;
    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                window.close();
            }
        }

        if (!isOver)
        {
            window.clear(bgColor);

            grid.DrawGrid(window);

            if (!snake.update(window, fruit))
            {
                isOver = true;
                gameOverSfx.play();
                int score = snake.getSnakePartsPosition().size() - 1;
                GameOver gameOver(score, window);
            }

            window.draw(fruit.getFruit());

            window.display();
        }
        else {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                isOver = false;
                snake.Reset();
                fruit.NewPosition(snake.getSnakePartsPosition());
            }
        }

        
    }

    return 0;
}
