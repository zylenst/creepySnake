#include "game.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>

void Game::run() {
    while (mWindow.isOpen()) {
        processEvents();
        update(mClock.restart());
        render();
    }
}