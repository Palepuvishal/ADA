#include <stdio.h>
#include <stdbool.h>

#define MAX 20

int board[MAX];

// Function to print the board
void printSolution(int n) {
    static int solutionCount = 1;
    printf("\nSolution %d:\n", solutionCount++);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i] == j)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}

// Check if the queen can be placed at board[row][col]
bool isSafe(int row, int col) {
    for (int i = 1; i < row; i++) {
        if (board[i] == col || (abs(board[i] - col) == abs(i - row))) {
            return false;
        }
    }
    return true;
}

// Recursive function to solve the N-Queens problem
void solveNQueens(int row, int n) {
    if (row > n) {
        printSolution(n);
        return;
    }

    for (int col = 1; col <= n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solveNQueens(row + 1, n);
        }
    }
}

int main() {
    int n;
    printf("Enter the value of N (size of the chessboard): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid board size. Please enter N between 1 and %d.\n", MAX);
        return 1;
    }

    printf("\nSolving %d-Queens Problem...\n", n);
    solveNQueens(1, n);

    return 0;
}
