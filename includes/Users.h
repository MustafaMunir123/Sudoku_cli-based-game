#ifndef USERS_H
#define USERS_H

#include <string>

class Users {
private:
    std::string name;
    int score;

public:
    Users();
    Users(const std::string& Name);
    Users(const Users& obj);
    ~Users();

    std::string getName();
    int getScore() const;
    void incrementScore();
};

#endif
