// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 2
// =============================================================================
//
// TASK: Student Grade System
//
// Write a C++ program that reads a student's score and outputs the
// corresponding letter grade based on the scale below.
//
// Grading Scale:
//   Score 80 – 100  →  Grade A
//   Score 70 – 79   →  Grade B
//   Score 60 – 69   →  Grade C
//   Score 50 – 59   →  Grade D
//   Score below 50  →  Grade F
//
// ---------------------------------------

#include <iostream>
using namespace std;

int main() {
    int score;

    cout << "Enter student score: ";
    cin >> score;

    if (score >= 80 && score <= 100) {
        cout << "Grade: A" << endl;
    } else if (score >= 70) {
        cout << "Grade: B" << endl;
    } else if (score >= 60) {
        cout << "Grade: C" << endl;
    } else if (score >= 50) {
        cout << "Grade: D" << endl;
    } else {
        cout << "Grade: F" << endl;
    }

    return 0;
}
