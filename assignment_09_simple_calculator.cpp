// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//
// The calculator should keep running and allow the user to do more
// calculations until they choose to quit.
//
// -----------------------------------------------------------------------------

#include <iostream>
#include <cmath>
using namespace std;

double calculate(double a, char op, double b) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') {
        if (b == 0) {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
        return a / b;
    }
    if (op == '%') return (int)a % (int)b;
    if (op == '^') return pow(a, b);
    return 0;
}

int main() {
    cout << "=== Simple Calculator ===" << endl;
    cout << "Supported operators: + - * / % ^" << endl;

    char again = 'y';

    while (again == 'y' || again == 'Y') {
        double num1, num2;
        char op;

        cout << "\nEnter first number: ";
        cin >> num1;
        cout << "Enter operator (+, -, *, /, %, ^): ";
        cin >> op;
        cout << "Enter second number: ";
        cin >> num2;

        double result = calculate(num1, op, num2);
        cout << "Result: " << num1 << " " << op << " " << num2 << " = " << result << endl;

        cout << "Do another calculation? (y/n): ";
        cin >> again;
    }

    cout << "Thank you for using the calculator!" << endl;

    return 0;
}
