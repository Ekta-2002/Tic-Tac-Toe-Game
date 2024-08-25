#include <iostream>
using namespace std;

const int SIZE = 3; // Tic-Tac-Toe board size
char board[SIZE][SIZE];

// Function prototypes
void initializeBoard();
void printBoard();
bool placeMark(int row, int col, char mark);
bool checkWin(char mark);
bool isBoardFull();
bool isValidMove(int row, int col);

int main() {
    char player = 'X';
    int row, col;
    bool gameEnded = false;

    initializeBoard();

    while (!gameEnded) {
        printBoard();
        cout << "Player " << player << ", enter row and column (0-2): ";
        cin >> row >> col;

        if (isValidMove(row, col)) {
            placeMark(row, col, player);

            if (checkWin(player)) {
                printBoard();
                cout << "Player " << player << " wins!" << endl;
                gameEnded = true;
            } else if (isBoardFull()) {
                printBoard();
                cout << "It's a draw!" << endl;
                gameEnded = true;
            } else {
                // Switch players
                player = (player == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "Invalid move, try again." << endl;
        }
    }

    return 0;
}

void initializeBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1) {
            cout << "---------" << endl;
        }
    }
}

bool placeMark(int row, int col, char mark) {
    if (board[row][col] == ' ') {
        board[row][col] = mark;
        return true;
    }
    return false;
}

bool checkWin(char mark) {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) ||
            (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
        (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)) {
        return true;
    }

    return false;
}

bool isBoardFull() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool isValidMove(int row, int col) {
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ');
}
