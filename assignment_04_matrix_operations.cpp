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
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two M x N matrices from the user.
// - Compute and display their sum.
//
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read an M x N matrix and an N x P matrix from the user.
// - Compute and display their product.
//
// -----------------------------------------------------------------------------

#include <iostream>
using namespace std;

void printMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[10][10], int rows, int cols) {
    int result[10][10];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    cout << "\nTransposed Matrix:" << endl;
    printMatrix(result, cols, rows);
}

void addMatrices(int a[10][10], int b[10][10], int rows, int cols) {
    int result[10][10];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    cout << "\nSum Matrix:" << endl;
    printMatrix(result, rows, cols);
}

void multiplyMatrices(int a[10][10], int b[10][10], int rowsA, int colsA, int colsB) {
    int result[10][10] = {0};
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    cout << "\nProduct Matrix:" << endl;
    printMatrix(result, rowsA, colsB);
}

int main() {
    int choice;
    cout << "Matrix Operations Menu:" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int rows, cols;
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        int matrix[10][10];
        cout << "Enter the matrix elements:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> matrix[i][j];
            }
        }

        cout << "\nOriginal Matrix:" << endl;
        printMatrix(matrix, rows, cols);
        transposeMatrix(matrix, rows, cols);

    } else if (choice == 2) {
        int rows, cols;
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        int a[10][10], b[10][10];
        cout << "Enter elements of first matrix:" << endl;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> a[i][j];

        cout << "Enter elements of second matrix:" << endl;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> b[i][j];

        addMatrices(a, b, rows, cols);

    } else if (choice == 3) {
        int rowsA, colsA, colsB;
        cout << "Enter rows of first matrix: ";
        cin >> rowsA;
        cout << "Enter columns of first matrix (= rows of second): ";
        cin >> colsA;
        cout << "Enter columns of second matrix: ";
        cin >> colsB;

        int a[10][10], b[10][10];
        cout << "Enter elements of first matrix:" << endl;
        for (int i = 0; i < rowsA; i++)
            for (int j = 0; j < colsA; j++)
                cin >> a[i][j];

        cout << "Enter elements of second matrix:" << endl;
        for (int i = 0; i < colsA; i++)
            for (int j = 0; j < colsB; j++)
                cin >> b[i][j];

        multiplyMatrices(a, b, rowsA, colsA, colsB);

    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
