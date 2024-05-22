#include "game.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>


Game::Game()
: mWindow(sf::VideoMode(800, 600), "Creepy Snake")
, mSnakeSegment(10.f)
, mFood(10.f)
, mDirection(8.f, 0.f)
, mMoveInterval(sf::seconds(speed))
, mIsMovingUp(false)
, mIsMovingDown(false)
, mIsMovingLeft(false)
, mIsMovingRight(false)
, mIsCreepyMode(false)
{
    mSnakeSegment.setFillColor(sf::Color::Green);
    mFood.setFillColor(sf::Color::Yellow);
    mSnake.push_back(sf::Vector2f(400.f, 300.f));

    // Set initial positions of the snake segments
    mSnake.push_back(sf::Vector2f(400.f, 300.f)); // Head of the snake
    mSnake.push_back(sf::Vector2f(380.f, 300.f)); // Second segment
    mSnake.push_back(sf::Vector2f(360.f, 300.f)); // Third segment
    mSnake.push_back(sf::Vector2f(340.f, 300.f)); // Fourth segment

    spawnFood();
    std::srand(std::time(nullptr));
}