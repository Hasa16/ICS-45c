#include "Functions.h"
#include <iostream>
#include <string>
using namespace std;


void runGame() // runs tic tac toe game
{
    char board[3][3] = {{},{},{}}; // initializes 3x3 board
    char turnO = 'O'; // sets a character for O
    char turnX = 'X'; // sets a character for X
    string replay; // string for replay input
    string input; // string for user turn input
    int x; // initializes x coordinate
    int y; // initializes y coordinate
    int i = 0; // initializes i = 0
    initBoard(board); // inserts '-' in each board space
    while(true) { // while loop
        if (i < 10){ // limits player moves to 9 
            if (i % 2 == 1){ // checks if it is player "O"'s turn
                cout << "Enter coordinate for " << turnO << ". Input should be X Y\n";
            }
            if (i % 2 == 0){ // checks if it is player "X"'s turn
                cout << "Enter coordinate for " << turnX << ". Input should be X Y\n";
            }
            cin >> x >> y; // takes in coordinate input and stores it into x y
            if (i % 2 == 1){ // places "O" on the coordinates of the board
                placeAPiece(x, y, turnO, board);
            }
            if (i % 2 == 0){ // places "X" on the coordinates of the board
                placeAPiece(x, y, turnX, board);
            }
            displayBoard(board); // displays the game board
            bool winO = checkForWinner(turnO, board); // checks if player "O" has won
            bool winX = checkForWinner(turnX, board); // checks if player "X" has won
            bool draw = checkForDraw(board); // checks if the game is a draw
            if (i % 2 == 1){ // checks who's turn it is
                if(winO == true){
                    cout << turnO << " Won" << endl; // prints out player "O" has won
                    break;
                }
                else if(draw == true){
                    cout << "Draw" << endl; // prints out a draw 
                    break;
                }
                else {
                    i = i + 1; // adds 1 to i
                    continue;
                }
            }
            if (i % 2 == 0){ // checks who's turn it is
                if(winX == true){
                    cout << turnX << " Won" << endl; // prints out player "X" has won
                    break;
                }
                else if(draw == true){
                    cout << "Draw" << endl; // prints out a draw 
                    break;
                }
                else {
                    i = i + 1; // adds 1 to i
                    continue;
                }
            }
        }
        break; // breaks loop
    }
    cout << "Do you want to play again?\n"; // asks user if they want to play again
    cin >> replay; // takes in response
    if(replay == "y"){ // checks if response is yes
        system("cls");
        restart();
    }
    else if(replay == "Y"){ // checks if response is yes
        system("cls");
        restart();
    }
    else if(replay == "N"){ // checks if response is no 
        cout << "Done\n";
    }
    else{ // checks if response is no 
        cout << "Done\n";
    }
}

void restart(){ // restarts the game
    runGame();
}


void initBoard(char board[3][3]) // places '-' in every board spot
{
    int i = 0;
    int c = 0;
    for (i = 0; i < 3; i++) { // for loop for x coordinate 
      for (c = 0; c < 3; c++) { // for loop for y coordinate 
        board[i][c] = '-'; // places '-' at board[x][y]
      }
    }
}

void placeAPiece(int x, int y, char piece, char board[3][3]) // places a piece at coordinates x, y
{
    board[x][y] = piece; // places piece at board[x][y]
}

bool checkForWinner(char piece, char board[3][3]) // checks if a player has won
{
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] == piece){
        return true;
        }
    else if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] == piece){
        return true;
        }
    else if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == piece){
        return true;
        }
    else if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] == piece){
        return true;
        }
    else if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] == piece){
        return true;
        }
    else if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] == piece){
        return true;
        }
    else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == piece){
        return true;
        }
    else if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] == piece){
        return true;
        }
    else{
        return false;
    }
}

bool checkForDraw(char board[3][3]) // checks for a draw
{
    int v = 0;
    int b = 0;
    int f = 0;
    for (v = 0; v < 3; v++) { // for loop for x coordinate 
      for (b = 0; b < 3; b++) { // for loop for Y coordinate 
        if (board[v][b] != '-'){ // counts amount of '-' on board
            f++;
        }
      }
    }
    if (f != 9){ // if amount of dashes != 9 game is still in progress
        return false;
    }
    else // else game is a draw
        return true;
}


void displayBoard(char board[3][3]) // displays game board
{
    cout << board[0][0] << "|" << board[0][1] << "|" << board[0][2] << endl;
    cout << "-----" << endl;
    cout << board[1][0] << "|" << board[1][1] << "|" << board[1][2] << endl;
    cout << "-----" << endl;
    cout << board[2][0] << "|" << board[2][1] << "|" << board[2][2] << endl;
}