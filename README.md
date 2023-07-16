# Resume_Project_Sudoku_Solver

I have created a project on Sudoku Solver. This project implements the concept of backtracking. Below is the description of the project.

The user will give a 9 x 9  2-D square matrix (matrix[][]) as input. Each cell of the matrix should be filled with numbers from 0 to 9. 0 will indicate a blank.
We can not replace the element in the cell which is not blank. The task is to find a solved Sudoku. For simplicity, we may assume that there will be only a unique solution.

A sudoku solution must satisfy all of the following rules:

1.Each of the digits 1-9 must occur exactly once in each row.
2.Each of the digits 1-9 must occur exactly once in each column.
3.Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

To use the  code, user will enter the Sudoku matrix as input. Use '0' to represent empty cells, and enter the digits row by row. The code will then attempt to solve the Sudoku puzzle and display the solution if one exists.

The code uses a backtracking algorithm to solve the Sudoku puzzle. It checks if a digit can be placed in a given row and column by verifying its absence in the same row, column and 3x3 box. If a digit is safe to place, it moves on to the next empty cell and continues solving recursively. If a solution is found, it prints the solved matrix; otherwise, it displays a message "The input given by the user doesn't make a valid Sudoku Problem".
