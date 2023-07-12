#include "Game.h"

Game::Game() {}

Game::Game(const std::string& name) {
    gameName = new std::string(name);
}

Game::~Game() {
    delete gameName;
}
