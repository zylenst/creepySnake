#include "game.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>


void Game::spawnFood() {
    mFood.setPosition(static_cast<float>(std::rand() % 80) * 10.f, static_cast<float>(std::rand() % 60) * 10.f);
}

void Game::checkCollisions() {
    const float collisionThreshold = 20.f; // You can adjust this value

    // Calculate the distance between the snake's head and the fruit
    sf::Vector2f headPosition = mSnake[0];
    sf::Vector2f foodPosition = mFood.getPosition();
    float distance = std::sqrt(std::pow(headPosition.x - foodPosition.x, 2) + std::pow(headPosition.y - foodPosition.y, 2));

    // Check if the distance is within the collision threshold
    if (distance < collisionThreshold) {
        mSnake.push_back(mSnake.back());
        spawnFood();
    }

    // for (std::size_t i = 1; i < mSnake.size(); ++i) {
    //     if (mSnake[0] == mSnake[i]) {
    //         mSnake = { mSnake[0] };
    //         break;
    //     }
    // }
}

void Game::toggleCreepyMode() {
    mIsCreepyMode = !mIsCreepyMode;
    mCreepyModeTime = sf::Time::Zero;
}
