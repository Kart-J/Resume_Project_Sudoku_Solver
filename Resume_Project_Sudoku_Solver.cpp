#include <iostream>
using namespace std;


// Function to print the Sudoku matrix
void printmatrix(int matrix[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++)
            cout << matrix[row][col] << " ";
        cout << endl;
    }
}

// Function to check if a digit can be placed in the given row and column
bool isSafe(int matrix[9][9], int row, int col, int digit) {
    // Check if the digit is already present in the row
    for (int i = 0; i < 9; i++) {
        if (matrix[row][i] == digit)
            return false;
    }

    // Check if the digit is already present in the column
    for (int i = 0; i < 9; i++) {
        if (matrix[i][col] == digit)
            return false;
    }

    // Check if the digit is already present in the 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i + startRow][j + startCol] == digit)
                return false;
        }
    }

    // The digit can be placed at the given row and column
    return true;
}

// Function to solve the Sudoku matrix using backtracking
bool solveSudoku(int matrix[9][9]) {
    int row, col;

    // Find the next empty cell
    bool isEmpty = false;
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (matrix[row][col] == 0) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty)
            break;
    }

    // If there are no empty cells, the Sudoku is solved
    if (!isEmpty)
        return true;

    // Try placing digits from 1 to 9
    for (int digit = 1; digit <= 9; digit++) {
        // Check if the digit can be placed at the current row and column
        if (isSafe(matrix, row, col, digit)) {
            // Place the digit at the current row and column
            matrix[row][col] = digit;

            // Recursively solve the remaining Sudoku
            if (solveSudoku(matrix))
                return true;

            // If the solution is not found, undo the current cell and try again
            matrix[row][col] = 0;
        }
    }

    // The Sudoku cannot be solved
    return false;
}

// Driver code
int main() {
    int matrix[9][9];

    cout << "Enter the Sudoku matrix (use 0 for empty cells):\n";
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            cin >> matrix[row][col];
        }
    }

    if (solveSudoku(matrix)) {
        cout << "\nSudoku solution:\n";
        printmatrix(matrix);
    } else {
        cout << "\nThe input given by the user doesn't make a valid Sudoku Problem.";
    }

    return 0;
}
