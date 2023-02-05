#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;


//Function Prototypes
void showMenu();

void playerMode(char[]);
void playAI(char[]);


void showBoard(char[]);
void updateBoard(char[], int);


char playerMove1();
char playerMove2();
int computerMove();


bool checkWin();
void checkInput(int);


int main() {
    char board[9] = { '1','2','3','4','5','6','7','8','9' };

    cout << "\n";
    cout << setw(55) << "FINAL PROJECT: TIC TAC TOE\n";
    cout << "\n";
    cout << "Welcome to Tic Tac Toe.\n";
    cout << "This program will allow you to play against either an AI or\n";
    cout << "another player. Choose a game mode below to start playing.\n";
    cout << "\n";
    cout << "__________________________________________________________________________\n";
    cout << "\n";

    char option, move;
    int move1;

    while (option != 'c' && option != 'C') {
        showMenu();
        cout << "Which game mode do you want to play: ";
        cin >> option;
        cout << "\n";
        cout << "\n";
        while (option != 'A' && option != 'B' && option != 'C' && option != 'a' && option != 'b' && option != 'c') {
            cout << "Invalid choice.\n";
            cout << "Please select one of the game modes by entering the associated letter.\n";
            cout << "Which game mode would you like to play: ";
            cin >> option;
            cout << "\n";
        }

        cout << "__________________________________________________________________________\n";
        cout << "\n";

        switch (option) {
        case 'A': cout << "You have chosen to the PLAYER v. PLAYER mode.\n";
            cout << "\n";
            cout << "* Press enter to continue *\n";
            cin.get();
            cin.get();
            playerMode(board);

            break;

        case 'a': cout << "You have chosen to the PLAYER v. PLAYER mode.\n";
            cout << "\n";
            cout << "* Press enter to continue *\n";
            cin.get();
            cin.get();
            playerMode(board);

            break;

        case 'B': cout << "You have chosen to the PLAYER v. AI mode.\n";
            cout << "\n";
            cout << "* Press enter to continue *\n";
            cin.get();
            cin.get();
            playAI(board);

            break;

        case 'b': cout << "You have chosen to the PLAYER v. AI mode.\n";
            cout << "\n";
            cout << "* Press enter to continue *\n";
            cin.get();
            cin.get();
            playAI(board);

            break;

        case 'C': cout << "You have chosen to EXIT and not play Tic Tac Toe.\n";
            exit(0);

            break;

        case 'c': cout << "You have chosen to EXIT and not play Tic Tac Toe.\n";
            exit(0);
        }

        cout << "__________________________________________________________________________\n";

    } //While loop curly brace

} //Main function curly brace 






//Functions

void playerMode(char board[]) {
    cout << "This is the board you will use to play Tic Tac Toe with another player.\n";
    cout << "\n";
    showBoard(board);
    cout << "\n";
    cout << "Let's start by having Player1 be 'X' and Player2 being 'O'. Now we can begin.\n";
    cout << "\n";
    char move = playerMove1();
    cin.get();
    cout << "\n";
    updateBoard(board, move);
}


void playAI(char board[]) {
    cout << "This is the board you will use to play Tic Tac Toe against the computer.\n";
    cout << "\n";
    showBoard(board);
    cout << "\n";
    cout << "Let's start by having Player1 be 'X' and the computer being 'O'. Now we\n";
    cout << "can begin.\n";
    cout << "\n";
    //Player Move Function and AI Move function

    cin.get();
    cout << "\n";

}


void showBoard(char board[]) {
    cout << setw(50) << "Tic Tac Toe Board\n";
    cout << "\n";
    cout << board[0] << " | " << board[1] << " | " << board[2] << "\n" << "----------" << endl;
    cout << board[3] << " | " << board[4] << " | " << board[5] << "\n" << "----------" << endl;
    cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

void updateBoard(char board[], int move) {
    cout << setw(50) << "Tic Tac Toe Board\n";
    cout << "\n";
    board[move - 1] = 'X';
    cout << board[0] << " | " << board[1] << " | " << board[2] << "\n" << "----------" << endl;
    cout << board[3] << " | " << board[4] << " | " << board[5] << "\n" << "----------" << endl;
    cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
}



void showMenu() {
    char choice;
    cout << setw(45) << "GAME MENU\n";

    cout << "Game Modes:\n";
    cout << "\n";
    cout << "A - PLAYER v. PLAYER\n";
    cout << "B - PLAYER v. AI\n";
    cout << "C - EXIT\n";
    cout << "\n";
}


char playerMove1() {
    char move;
    cout << "What is your move: ";
    cin >> move;
    while (move != '1' && move != '2' && move != '3' && move != '4' && move != '5' && move != '6' && move != '7' && move != '8' && move != '9') {
        cout << "Invalid input.\n";
        cout << "Enter a number that is on the board: ";
        cin >> move;
        checkInput(move);
    }
    return move;
}


char playerMove2() {
    char move;
    cout << "What is your move: ";
    cin >> move;
    while (move != '1' && move != '2' && move != '3' && move != '4' && move != '5' && move != '6' && move != '7' && move != '8' && move != '9') {
        cout << "Invalid input.\n";
        cout << "Enter a number that is on the board: ";
        cin >> move;
        checkInput(move);
    }
    return move;
}

int computerMove() {
    int move;
    srand(time(0));
    move = (rand() % 10 + 1);
    return move;
}

bool checkWin() {
    // If the there is a winning series, 
    return true;
}

void checkInput(char board[], int move) {
    while (board[move - 1] == 'X' || board[move - 1] == '0')
        cout << "Spot has already been selected, please choose a different move.\n";
    cin >> move;
}