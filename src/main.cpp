#include "game.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "renderEngine.cpp"
#include "events.cpp"
#include "eventHandler.cpp"
#include "runner.cpp"
#include "frameUpdater.cpp"
#include "init.cpp"
#include "inputHandler.cpp"

int main() {
    Game game;
    game.run();
    return 0;
}