#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

void printBoard(const vector<vector<char>>& board) {
    cout << endl;
    for (int i = 0; i < 3; i++) {
        cout << " | ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        if (i != 2) cout << endl << "-----" << endl;
    }
    cout << endl;
}

bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

      if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                return false;
            }
        }
    }

    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, '-'));
    char currentPlayer = 'X';
    bool playAgain = true;
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    while (playAgain) {

        printBoard(board);

        int row, col;
        bool validMove = false;

        do {
            cout << "Player " << currentPlayer << ", enter your move (row [0-2] and column [0-2]): ";
            cin >> row >> col;

            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == '-') {
                board[row][col] = currentPlayer;
                validMove = true;
            } else {
                cout << "Invalid move. Try again." << endl;
            }

        } while (!validMove);

        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
        } else if (checkDraw(board)) {
            printBoard(board);
            cout << "The game is a draw!" << endl;
        } else {
            currentPlayer = currentPlayer == 'X' ? 'O' : 'X';
        }



    }

    cout << "Thanks for playing!" << endl;

    return 0;
}
