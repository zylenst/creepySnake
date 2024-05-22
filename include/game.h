#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class Game {
public:
    Game();
    void run();
    float jump = 5.;

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    void spawnFood();
    void checkCollisions();
    void toggleCreepyMode();

    sf::RenderWindow mWindow;
    sf::CircleShape mSnakeSegment;
    std::vector<sf::Vector2f> mSnake;
    sf::CircleShape mFood;
    sf::Vector2f mDirection;
    sf::Time mTimeSinceLastMove;
    sf::Time mMoveInterval;
    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingLeft;
    bool mIsMovingRight;
    bool mIsCreepyMode;
    sf::Time mCreepyModeTime;
    sf::Clock mClock;
};

#endif // GAME_H
