#ifndef SUDOKU_H
#define SUDOKU_H

#include "Game.h"
#include "Users.h"

class Sudoku : public Game {
    static const int board_size;
    static int board[9][9];
    Users* players;
    int noOfPlayers = 0;

public:
    Sudoku();

protected:
    bool validBoard();

public:
    void howToPlay();
    void about();
    void printBoard();
    void startGame();
    void leaderboard();
    void checkWinner();
    void playerTurn();
};

#endif  // SUDOKU_H
