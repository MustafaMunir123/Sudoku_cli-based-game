#ifndef GAME_H
#define GAME_H

#include <string>

class Game {
protected:
    std::string* gameName;

protected:
    Game();
    Game(const std::string& name);

    virtual void about() = 0;
    virtual void howToPlay() = 0;
    virtual void leaderboard() = 0;

    virtual ~Game();
};

#endif  // GAME_H
