#include <stdio.h>
#include <stdlib.h>

char board[3][3];   // 2D array to store the tic-tac-toe board
char player = 'X';  // Starting player is X

void initialize_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

void print_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void make_move() {
    int row, col;
    printf("Player %c's turn. Enter row and column: ", player);
    scanf("%d %d", &row, &col);
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        printf("Invalid move. Try again.\n");
        make_move();
    } else if (board[row][col] != '-') {
        printf("That spot is already taken. Try again.\n");
        make_move();
    } else {
        board[row][col] = player;
    }
}

char check_winner() {
    int i, j;
    char winner = '-';
    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            winner = board[i][0];
        }
    }
    // Check columns
    for (j = 0; j < 3; j++) {
        if (board[0][j] != '-' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            winner = board[0][j];
        }
    }
    // Check diagonals
    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        winner = board[0][0];
    } else if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        winner = board[0][2];
    }
    return winner;
}

int main() {
    initialize_board();
    print_board();
    int i;
    for (i = 0; i < 9; i++) {
        make_move();
        print_board();
        char winner = check_winner();
        if (winner != '-') {
            printf("Player %c wins!\n", winner);
            return 0;
        }
        if (player == 'X') {
            player = 'O';
        } else {
            player = 'X';
        }
    }
    printf("It's a tie!\n");
    return 0;
}
