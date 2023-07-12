#include <iostream>
#include <string>
#include <conio.h>
#include "includes/Users.h"
#include "includes/Game.h"
#include "includes/Sudoku.h"

using namespace std;

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