#include <iostream>
#include <string>

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

    // virtual void About() = 0;
    // virtual void GameMode() = 0;
    // virtual void HowToPlay() = 0;

    // Destructor
    virtual ~Game() {
        delete gameName;
    }
};

class Users {
private:
    string name;
    int score;

public:
    Users(){}

    Users(const string &Name) {
        name = Name;
        score = 0;
    }

    Users(const Users& obj) {
        name = obj.name;
        score = obj.score;
    }

    ~Users() {}

    string getName() {
        return this->name;
    }

    int getScore() const {
        return this->score;
    }

    void incrementScore() {
    this->score += 1;
}

};

class Sudoku : public Game {
    static const int board_size;
    static int board[9][9];
    Users *players;
    int noOfPlayers;

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


void playerTurn() {

    bool gameOver = false;
    bool playerLoses[noOfPlayers] = {false};
    int *playerIncorrect;
    playerIncorrect = new int[noOfPlayers];

    for (int i=0; i<noOfPlayers; i++){
        playerIncorrect[i] = 0;
    }
    // int player2Incorrect = 0;

    while (!gameOver) {
        for (int i=0; i<noOfPlayers; i++){

            //Checks if players lost all 3 attemts 
            int lostCount = 0;
            for (int i=0; i<noOfPlayers; i++){
                if (playerIncorrect[i] == 3){
                    lostCount += 1;
                    cout << players[i].getName() << " loses" << endl;
                    playerLoses[i] = true;
                };
            }
            // if all n players lost, game is over.
            if (lostCount == noOfPlayers){
                gameOver = true;
            }
            
            printBoard();

            while (!playerLoses[i]) {
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
                        printBoard();
                        players[i].incrementScore();
                        break;
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

    // Users mm("mm", 0);
    // Users pp("pp", 0);

    Sudoku game;
    // game.printBoard(mm , pp);
    game.startGame();

    return 0;
};