#include "game.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>

void Game::update(sf::Time deltaTime) {
    mTimeSinceLastMove += deltaTime;

    if (mTimeSinceLastMove >= mMoveInterval) {
        mTimeSinceLastMove = sf::Time::Zero;

        if (mIsMovingUp) {
            mDirection = mIsCreepyMode ? sf::Vector2f(0.f, 8.f) : sf::Vector2f(0.f, -8.f);
        } else if (mIsMovingDown) {
            mDirection = mIsCreepyMode ? sf::Vector2f(0.f, -8.f) : sf::Vector2f(0.f, 8.f);
        } else if (mIsMovingLeft) {
            mDirection = mIsCreepyMode ? sf::Vector2f(8.f, 0.f) : sf::Vector2f(-8.f, 0.f);
        } else if (mIsMovingRight) {
            mDirection = mIsCreepyMode ? sf::Vector2f(-8.f, 0.f) : sf::Vector2f(8.f, 0.f);
        }

        for (std::size_t i = mSnake.size() - 1; i > 0; --i) { //Moves Each segment
            mSnake[i] = mSnake[i - 1];                        //of snake
        }                                                     //in the required direction
        mSnake[0] += mDirection;                              //by updating mDirection vector

        checkCollisions();

        if (std::rand() % 100 < 2) {
            toggleCreepyMode();
        }

        if (mIsCreepyMode) {
            mCreepyModeTime += deltaTime;
            if (mCreepyModeTime.asSeconds() >= 10.f) {
                mIsCreepyMode = false;
                mCreepyModeTime = sf::Time::Zero;
            }
        }
    }
}