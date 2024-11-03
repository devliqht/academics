#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define N 9

bool isValid(int board[N][N], int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num || board[i][col] == num)
            return false;
    }
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num)
                return false;
        }
    }
    return true;
}

void shuffle(int *array, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

bool fillBoard(int board[N][N], int row, int col) {
    if (row == N - 1 && col == N)
        return true;

    if (col == N) {
        row++;
        col = 0;
    }

    if (board[row][col] != 0)
        return fillBoard(board, row, col + 1);

    int nums[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    shuffle(nums, N);  

    for (int i = 0; i < N; i++) {
        if (isValid(board, row, col, nums[i])) {
            board[row][col] = nums[i];
            if (fillBoard(board, row, col + 1))
                return true;

            // If we can't proceed, backtrack
            board[row][col] = 0;
        }
    }

    return false;  // Trigger backtracking
}

// Function to print the Sudoku board
void printBoard(int board[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

// Function to generate a complete valid Sudoku board
void generateSudoku(int board[N][N]) {
    // Seed the random number generator
    srand(time(0));

    // Initialize the board with zeros
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    // Fill the board with valid numbers
    fillBoard(board, 0, 0);
}

int main() {
    int board[N][N];

    // Generate a valid Sudoku board
    generateSudoku(board);

    // Print the generated Sudoku board
    printBoard(board);

    return 0;
}