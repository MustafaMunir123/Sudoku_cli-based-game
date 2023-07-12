#include <iostream>
#include "Users.h"

using namespace std;


    Users::Users(){}

    Users::Users(const string &Name) {
        name = Name;
        score = 0;
    }

    Users::Users(const Users& obj) {
        name = obj.name;
        score = obj.score;
    }

    Users::~Users() {}

    string Users::getName() {
        return this->name;
    }

    int Users::getScore() const {
        return this->score;
    }

    void Users::incrementScore() {
    this->score += 1;
}

