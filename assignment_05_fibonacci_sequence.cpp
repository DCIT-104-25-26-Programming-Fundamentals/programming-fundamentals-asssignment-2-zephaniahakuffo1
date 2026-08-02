// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms they want.
// - Print the Fibonacci sequence up to that many terms.
//
// PART B — Check if a Number is in the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Check if that number appears in the Fibonacci sequence.
// - Print whether it is or is not a Fibonacci number.
//
// -----------------------------------------------------------------------------

#include <iostream>
using namespace std;

void printFibonacci(int n) {
    int a = 0, b = 1;
    cout << "Fibonacci sequence: ";
    for (int i = 0; i < n; i++) {
        cout << a;
        if (i < n - 1) cout << ", ";
        int next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

bool isFibonacci(int num) {
    int a = 0, b = 1;
    while (a < num) {
        int next = a + b;
        a = b;
        b = next;
    }
    return a == num;
}

int main() {
    int n;
    cout << "Enter how many terms of Fibonacci to print: ";
    cin >> n;
    printFibonacci(n);

    int num;
    cout << "\nEnter a number to check if it is a Fibonacci number: ";
    cin >> num;

    if (isFibonacci(num)) {
        cout << num << " is a Fibonacci number." << endl;
    } else {
        cout << num << " is not a Fibonacci number." << endl;
    }

    return 0;
}
