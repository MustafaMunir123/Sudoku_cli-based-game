#include <iostream>
#include <string>
#include <conio.h>
#include "Users.h"
#include "Game.h"
#include "Sudoku.h"


using namespace std;

// Abstract Game Class
class Game {
protected:
    string* gameName;
protected:
    Game(){};

    Game(const string& name) {
        gameName = new string(name);
    }

    virtual void about() = 0;
    virtual void howToPlay() = 0;
    virtual void leaderboard() = 0;

    // Destructor
    virtual ~Game() {
        delete gameName;
    }
};


class Sudoku : public Game {
    static const int board_size;
    static int board[9][9];
    Users *players;
    int noOfPlayers = 0;

    public:
    Sudoku(){};

    protected:
    bool validBoard() {
    // Check rows
    for (int row = 0; row < 9; ++row) {
        bool used[10] = {false};  // Array to track used numbers (from 1 to 9)
        for (int col = 0; col < 9; ++col) {
            int num = board[row][col];
            if (num != 0) {
                if (used[num]) {
                    return false;  // Duplicate number found in the row
                }
                used[num] = true;
            }
        }
    }

    // Check columns
    for (int col = 0; col < 9; ++col) {
        bool used[10] = {false};  // Array to track used numbers (from 1 to 9)
        for (int row = 0; row < 9; ++row) {
            int num = board[row][col];
            if (num != 0) {
                if (used[num]) {
                    return false;  // Duplicate number found in the column
                }
                used[num] = true;
            }
        }
    }

    // Check 3x3 squares
    for (int blockRow = 0; blockRow < 9; blockRow += 3) {
        for (int blockCol = 0; blockCol < 9; blockCol += 3) {
            bool used[10] = {false};  // Array to track used numbers (from 1 to 9)
            for (int row = blockRow; row < blockRow + 3; ++row) {
                for (int col = blockCol; col < blockCol + 3; ++col) {
                    int num = board[row][col];
                    if (num != 0) {
                        if (used[num]) {
                            return false;  // Duplicate number found in the 3x3 square
                        }
                        used[num] = true;
                    }
                }
            }
        }
    }
    return true; 
    }

    public:
    void howToPlay() {
            cout << "==========================" << endl;
            cout << "       HOW TO PLAY        " << endl;
            cout << "==========================" << endl;
            cout << "1. Sudoku is played on a 9x9 grid." << endl;
            cout << "2. The grid is divided into 9 smaller 3x3 grids." << endl;
            cout << "3. The goal is to fill in the grid so that every row, column, and 3x3 grid contains the numbers 1-9, with no repeats." << endl;
            cout << "4. Some numbers are already provided as clues." << endl;
            cout << "5. You need to fill in the remaining empty cells with the correct numbers." << endl;
            cout << "6. Use the numbers 1-9 to fill in the empty cells." << endl;
            cout << "7. Each row, column, and 3x3 grid must contain the numbers 1-9 with no repeats." << endl;
            cout << "8. The game is complete when the entire grid is filled correctly." << endl;
            cout << "9. Good luck and enjoy playing Sudoku!" << endl;
            cout << "==========================" << endl;
            cout << "\nPress any [key] to continue" << endl;
            getch();
        }

    void about(){
        cout << "============================" << endl;
        cout << "           ABOUT US         " << endl;
        cout << "============================" << endl;
        cout << endl;
        cout << "We are Mustafa Munir and Azmeer Azhar, two students of NED University's" << endl;
        cout << "Department of Computer Science. We have developed a C++ based SUDOKU game." << endl;
        cout << endl;
        cout << "Student Details:" << endl;
        cout << "Mustafa Munir - CT-20302 - 3rd Year" << endl;
        cout << "Azmeer Azhar - CT-20100 - 3rd Year" << endl;
        cout << endl;
        cout << "Our passion for programming and problem-solving led us to create this SUDOKU" << endl;
        cout << "game as a way to showcase our skills and provide a challenging and enjoyable" << endl;
        cout << "experience for players." << endl;
        cout << endl;
        cout << "We have put in a lot of effort and dedication into this project, implementing" << endl;
        cout << "the game logic, user interface, and various features to ensure a seamless" << endl;
        cout << "and engaging gameplay." << endl;
        cout << endl;
        cout << "We hope that our SUDOKU game brings joy to all the puzzle enthusiasts out there." << endl;
        cout << "Thank you for your support!" << endl;
        cout << "\nPress any [key] to continue" << endl;
        getch();
    }

    void printBoard() {
        cout << "\nSudoku Board:\t";
        for (int i = 0; i < noOfPlayers; i++) {
            cout << this->players[i].getName() << ": " << players[i].getScore() << "\t";
        }

        cout << "\n+-------+-------+-------+" << endl;
        for (int i = 0; i < board_size; i++) {
            if (i != 0 && i % 3 == 0) {
                cout << "+-------+-------+-------+" << endl;
            }
            for (int j = 0; j < board_size; j++) {
                if (j % 3 == 0) {
                    cout << "| ";
                }
                if (board[i][j] == 0){
                    cout << ". " ;
                } else{
                cout << board[i][j] << " ";
                }
            }
            cout << "|" << endl;
        }
        cout << "+-------+-------+-------+" << endl;
        cout << endl;

    }

void startGame(){
    string name;

    cout << "\nEnter no. of players (1-4)" << endl;
    cin >> noOfPlayers;
    players = new Users[noOfPlayers];

    cout << "\nPlayers Info:";
    for (int i=0; i<noOfPlayers; i++){
        cout << "\nEnter name: ";
        cin >> name;

        players[i] = Users(name);
    }

    playerTurn();
}

void leaderboard(){
    cout << "\n~~~~~~~~~ SUDOKU Leader Board ~~~~~~~~~" << endl;
    if (noOfPlayers > 0) {
    for (int i=0; i<noOfPlayers; i++){
        cout << i+1 << ". " << players[i].getName() << "\t" << players[i].getScore() << endl;
        }
    };
    cout << "\nPress any [key] to continue" << endl;
    getch();
}

void checkWinner() {
    int maxScore = 0;
    int winnerIndex = -1;

    for (int i = 0; i < noOfPlayers; i++) {
        if (players[i].getScore() > maxScore) {
            maxScore = players[i].getScore();
            winnerIndex = i;
        }
    }

    if (winnerIndex != -1) {
        cout << "\n~~~~~~~~~ SUDOKU Winner ~~~~~~~~~" << endl;
        cout << "Winner: " << players[winnerIndex].getName() << endl;
        cout << "Score: " << players[winnerIndex].getScore() << endl;
    } else {
        cout << "\nNo winner. All players have the same score." << endl;
    }
}

void playerTurn() {

    bool gameOver = false;
    bool playerLoses[noOfPlayers] = {false};
    int *playerIncorrect;
    playerIncorrect = new int[noOfPlayers];

    for (int i=0; i<noOfPlayers; i++){
        playerIncorrect[i] = 0;
    }

    while (!gameOver) {
        for (int i=0; i<noOfPlayers; i++){

            //Checks if players lost all 3 attemts 
            int lostCount = 0;
            if (!gameOver){
                for (int i=0; i<noOfPlayers; i++){
                    if (playerIncorrect[i] == 3){
                        lostCount += 1;
                        cout << players[i].getName() << " has no more turns left" << endl;
                        playerLoses[i] = true;
                        getch();
                    };
                }
            }

            // if all n players lost, game is over.
            if (lostCount == noOfPlayers){
                gameOver = true;
            }

            while (!playerLoses[i]) {
                printBoard();
                cout << "\n" << players[i].getName() << "'s Turn" << endl;
                int row, column, input;
                
                cout << "Select row (1-9): ";
                cin >> row;
                cout << "Select column (1-9): ";
                cin >> column;

                // Adjust to 0-based index
                row--;
                column--;

                if (row < 0 || row >= board_size || column < 0 || column >= board_size) {
                    cout << "Invalid row or column. Please try again." << endl;
                    continue;
                }

                if (board[row][column] == 0) {
                    cout << "Enter a number from 1-9: ";
                    cin >> input;
                    if (input < 1 || input > 9) {
                        cout << "Invalid input. Please try again." << endl;
                        continue;
                    }

                    board[row][column] = input;
                    if (validBoard()) {
                        // printBoard();
                        players[i].incrementScore();
                        // checkWinner();
                        // break;
                    } else {
                        playerIncorrect[i]++;
                        cout << "\nWrong move!!! " << 3 - playerIncorrect[i] << " incorrect attempts left of player: " << players[i].getName() << endl;
                        board[row][column] = 0;
                        break;
                    }
                } else {
                    cout << "\nCannot insert here!!!" << endl;
                    continue;
                }
            }

            if (playerIncorrect[i] == 3)
                continue;
            }
        }
    checkWinner();
    getch();
    }

};

const int Sudoku::board_size = 9;
int Sudoku::board[board_size][board_size] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

int main() {
    bool q = true;
    int choice;
    Sudoku game;

    while (q)
    {   
        system("cls");
        cout << "\n-------------SUDOKU BOARD GAME-------------" << endl;
        cout << "___________________________________________" << endl;
        cout << "|  1. \t\tStart Game                |" << endl;
        cout << "|_________________________________________|" << endl;
        cout << "|  2. \t\tLeaderboard               |" << endl;
        cout << "|_________________________________________|" << endl;
        cout << "|  3. \t\tHow to Play               |" << endl;
        cout << "|_________________________________________|" << endl;
        cout << "|  4. \t\tAbout Us                  |" << endl;
        cout << "|_________________________________________|" << endl;
        cout << "|  5. \t\tQuit                      |" << endl;
        cout << "|_________________________________________|" << endl;

        cout << "\n  >> ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            game.startGame();
            break;
        case 2:
            game.leaderboard();
            break;
        case 3:
            game.howToPlay();
            break;
        case 4:
            game.about();
            break;
        case 5:
            q = false;
            cout << "\nexiting . . ." << endl;
            break;
        default:
            cout << "\nNot a valid choice !!!" << endl;
            break;
        }

    }    

    return 0;
};