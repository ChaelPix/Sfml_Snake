#include "Snake.h"



Snake::Snake(int pixelSize, int nbPixels)
{
    this->pixelSize = pixelSize;
    this->nbPixels = nbPixels;
    pickupSfx.Initialize("collect.wav");

    CreateNewSnake();
}

void Snake::CreateNewSnake()
{
    snakePixel.setSize(sf::Vector2f(pixelSize, pixelSize));
    snakePixel.setFillColor(sf::Color::Green);
    snakePartsPosition.push_back(sf::Vector2f(nbPixels / 2, nbPixels / 2));
}

void Snake::Reset()
{
    snakePartsPosition.clear();
    CreateNewSnake();
}

bool Snake::update(sf::RenderWindow &window, Fruit& fruit)
{
    //check player inpu
    ListenMoveInput();

    //update pos
    for (int i = snakePartsPosition.size()-1; i > 0 ; i--)
        snakePartsPosition[i] = snakePartsPosition[i-1];
    
    snakePartsPosition[0] += directionMap[actualDirection];

    //check fruit
    if (snakePartsPosition[0] == fruit.getPixelPosition())
    {
        ExtendSnake();
        pickupSfx.play();
        fruit.NewPosition(snakePartsPosition);
    }

    //Check Collision
    for (int i = 1; i < snakePartsPosition.size(); i++)
    {
        if (snakePartsPosition[0] == snakePartsPosition[i])
            return false;
    }

    if(snakePartsPosition[0].x < 0 || snakePartsPosition[0].x > nbPixels || 
        snakePartsPosition[0].y < 0 || snakePartsPosition[0].y > nbPixels)
        return false;


    //draw snake
    for (int i = 0; i < snakePartsPosition.size(); i++)
    {
        sf::RectangleShape pixel = snakePixel;
        pixel.setPosition(snakePartsPosition[i].x * pixelSize, snakePartsPosition[i].y * pixelSize);
        window.draw(pixel);
    }

    return true;
}

void Snake::ExtendSnake()
{
    sf::Vector2f newPartPos = sf::Vector2f(
        snakePartsPosition[snakePartsPosition.size() - 1].x + directionMap[actualDirection].x * -1,
        snakePartsPosition[snakePartsPosition.size() - 1].y + directionMap[actualDirection].y * -1);
    snakePartsPosition.push_back(newPartPos);
}

void Snake::ListenMoveInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        ChangeSnakeDirection(Direction::Right);

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        ChangeSnakeDirection(Direction::Left);

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        ChangeSnakeDirection(Direction::Bottom);

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        ChangeSnakeDirection(Direction::Up);
}

void Snake::ChangeSnakeDirection(Direction direction)
{
    //lambda function
    auto isValidDirectionChange = [](Direction current, Direction newDirection) {
        return (current == Direction::Left && newDirection != Direction::Right) ||
            (current == Direction::Right && newDirection != Direction::Left) ||
            (current == Direction::Up && newDirection != Direction::Bottom) ||
            (current == Direction::Bottom && newDirection != Direction::Up);
    };

    if (isValidDirectionChange(actualDirection, direction))
        actualDirection = direction;
    
}

std::vector<sf::Vector2f> Snake::getSnakePartsPosition()
{
    return snakePartsPosition;
}