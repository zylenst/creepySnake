#include "game.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>

void Game::render() {
    mWindow.clear(mIsCreepyMode ? sf::Color::Red : sf::Color::Black);

    for (const auto& segment : mSnake) {
        mSnakeSegment.setPosition(segment);
        mWindow.draw(mSnakeSegment);
        std::cout<<speed;
    }

    mWindow.draw(mFood);
    mWindow.display();
}