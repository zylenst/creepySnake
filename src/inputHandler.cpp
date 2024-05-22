#include "game.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>


void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::W || key == sf::Keyboard::Up) {
        mIsMovingUp = isPressed;
    } else if (key == sf::Keyboard::S || key == sf::Keyboard::Down) {
        mIsMovingDown = isPressed;
    } else if (key == sf::Keyboard::A || key == sf::Keyboard::Left) {
        mIsMovingLeft = isPressed;
    } else if (key == sf::Keyboard::D || key == sf::Keyboard::Right) {
        mIsMovingRight = isPressed;
    }
}