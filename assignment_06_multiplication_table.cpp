// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// PART B — Full Table (1 to 12 for all numbers)
// -----------------------------------------------------------------------------
// - Print a full multiplication table grid from 1 to 12.
//
// -----------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

void printSingleTable(int n) {
    cout << "\nMultiplication table for " << n << ":" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << n << " x " << i << " = " << n * i << endl;
    }
}

void printFullTable() {
    cout << "\nFull Multiplication Table (1-12):" << endl;
    cout << setw(4) << " ";
    for (int i = 1; i <= 12; i++) {
        cout << setw(4) << i;
    }
    cout << endl;

    for (int i = 1; i <= 12; i++) {
        cout << setw(4) << i;
        for (int j = 1; j <= 12; j++) {
            cout << setw(4) << i * j;
        }
        cout << endl;
    }
}

int main() {
    int number;
    cout << "Enter a number for its multiplication table: ";
    cin >> number;

    printSingleTable(number);

    cout << "\nDo you want to see the full table from 1 to 12? (1 = yes, 0 = no): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        printFullTable();
    }

    return 0;
}
