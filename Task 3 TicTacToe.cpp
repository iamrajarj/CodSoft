//Sachal Raja Task03

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

void displayBoard(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 5; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < 5; ++j) {
                if (j % 2 == 0) {
                    std::cout << board[i / 2][j / 2];
                } else {
                    std::cout << "|";
                }
            }
        } else {
            std::cout << "-----";
        }
        std::cout << std::endl;
    }
}

bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
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

bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    std::cout << "\t\tTic-Tac-Toe Game" << std::endl;
    cout<<"Game Rules: \n1. There are two players, Player X and Player O. Player X moves first.\n2. The top row is Row 0 all the way down to Row 2 and The left most column is Column 0 all the way right to Column 2.\n3. To win the Game a player has to form a line of 3 strokes either vertically, horizontally or diagonally. The first one to do wins the game.\n\n Happy Playing!\n\n"<<endl;

    while (!gameWon && !gameDraw) {
        displayBoard(board);

        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;
        
        system("cls");

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            if (checkWin(board, currentPlayer)) {
                gameWon = true;
                displayBoard(board);
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
            } else {
                if (checkDraw(board)) {
                    gameDraw = true;
                    displayBoard(board);
                    std::cout << "It's a draw!" << std::endl;
                } else {
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            }
        } else {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }

    displayBoard(board);

    return 0;
}
