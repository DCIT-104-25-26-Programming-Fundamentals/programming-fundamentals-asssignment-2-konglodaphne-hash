// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
const int MAX = 10;

void readMatrix(int arr[MAX][MAX], int rows, int cols, string matrixName) {
    cout << "Enter values for " << matrixName << " (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
}

void printMatrix(const int arr[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << arr[i][j]; 
        }
        cout << endl; 
    }
}
void transposeMatrix(const int input[MAX][MAX], int output[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            output[j][i] = input[i][j];
        }
    }
}
void addMatrices(const int A[MAX][MAX], const int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyMatrices(const int A[MAX][MAX], const int B[MAX][MAX], int result[MAX][MAX], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            
            
            result[i][j] = 0; 
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}


int main() {
    int A[MAX][MAX];
    int B[MAX][MAX];
    int result[MAX][MAX];
    cout << "==========================================" << endl;
    cout << "           PART A: TRANSPOSE              " << endl;
    cout << "==========================================" << endl;
    
    int rA, cA;
    cout << "Enter number of rows: ";
    cin >> rA;
    cout << "Enter number of columns: ";
    cin >> cA;

    readMatrix(A, rA, cA, "Original Matrix");

    cout << "Original Matrix:" << endl;
    printMatrix(A, rA, cA);

    transposeMatrix(A, result, rA, cA);

    cout << "Transposed Matrix:" << endl;
    printMatrix(result, cA, rA);

    cout << "==========================================" << endl;
    cout << "           PART B: ADDITION               " << endl;
    cout << "==========================================" << endl;
    
    int rAdd, cAdd;
    cout << "Enter number of rows for both matrices: ";
    cin >> rAdd;
    cout << "Enter number of columns for both matrices: ";
    cin >> cAdd;

    readMatrix(A, rAdd, cAdd, "Matrix A");
    readMatrix(B, rAdd, cAdd, "Matrix B");
    addMatrices(A, B, result, rAdd, cAdd);

    cout << "Result of (A + B):" << endl;
    printMatrix(result, rAdd, cAdd);

    cout << "==========================================" << endl;
    cout << "         PART C: MULTIPLICATION           " << endl;
    cout << "==========================================" << endl;
    
    int rowsA_mult, colsA_mult;
    int rowsB_mult, colsB_mult;

    cout << "Enter rows for Matrix A: ";
    cin >> rowsA_mult;
    cout << "Enter columns for Matrix A: ";
    cin >> colsA_mult;

    cout << "Enter rows for Matrix B: ";
    cin >> rowsB_mult;
    cout << "Enter columns for Matrix B: ";
    cin >> colsB_mult;

    
    if (colsA_mult != rowsB_mult) {
        cout << "Error: Multiplication not possible!" << endl;
        cout << "Columns of A (" << colsA_mult << ") must equal Rows of B (" << rowsB_mult << ")." << endl;
    } else {
        readMatrix(A, rowsA_mult, colsA_mult, "Matrix A");
        readMatrix(B, rowsB_mult, colsB_mult, "Matrix B");
        multiplyMatrices(A, B, result, rowsA_mult, colsA_mult, colsB_mult);

        cout << "Result of (A x B):" << endl;
        printMatrix(result, rowsA_mult, colsB_mult);
    }

    return 0;
}

