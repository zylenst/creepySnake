#include "game.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>

float speed = 0.05;

Game::Game()
: mWindow(sf::VideoMode(800, 600), "Creepy Snake")
, mSnakeSegment(10.f)
, mFood(10.f)
, mDirection(5.f, 0.f)
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
    spawnFood();
    std::srand(std::time(nullptr));
}

void Game::run() {
    while (mWindow.isOpen()) {
        processEvents();
        update(mClock.restart());
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                mWindow.close();
                break;
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
        }
    }
}

void Game::update(sf::Time deltaTime) {
    mTimeSinceLastMove += deltaTime;

    if (mTimeSinceLastMove >= mMoveInterval) {
        mTimeSinceLastMove = sf::Time::Zero;

        if (mIsMovingUp) {
            mDirection = mIsCreepyMode ? sf::Vector2f(0.f, 5.f) : sf::Vector2f(0.f, -5.f);
        } else if (mIsMovingDown) {
            mDirection = mIsCreepyMode ? sf::Vector2f(0.f, -5.f) : sf::Vector2f(0.f, 5.f);
        } else if (mIsMovingLeft) {
            mDirection = mIsCreepyMode ? sf::Vector2f(5.f, 0.f) : sf::Vector2f(-5.f, 0.f);
        } else if (mIsMovingRight) {
            mDirection = mIsCreepyMode ? sf::Vector2f(-5.f, 0.f) : sf::Vector2f(5.f, 0.f);
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

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::W) {
        mIsMovingUp = isPressed;
    } else if (key == sf::Keyboard::S) {
        mIsMovingDown = isPressed;
    } else if (key == sf::Keyboard::A) {
        mIsMovingLeft = isPressed;
    } else if (key == sf::Keyboard::D) {
        mIsMovingRight = isPressed;
    }
}

void Game::spawnFood() {
    mFood.setPosition(static_cast<float>(std::rand() % 80) * 10.f, static_cast<float>(std::rand() % 60) * 10.f);
}

void Game::checkCollisions() {
    if (mSnake[0] == mFood.getPosition()) {
        mSnake.push_back(sf::Vector2f(400.f, 300.f));
        spawnFood();
        speed = speed - speed/2.f;
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

int main() {
    Game game;
    game.run();
    return 0;
}