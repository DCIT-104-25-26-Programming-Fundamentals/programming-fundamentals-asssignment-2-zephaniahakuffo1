// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------

#include <iostream>
using namespace std;

double findSum(double arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

double findAverage(double arr[], int size) {
    return findSum(arr, size) / size;
}

double findMax(double arr[], int size) {
    double max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

double findMin(double arr[], int size) {
    double min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int n;

    cout << "How many numbers do you want to enter? ";
    cin >> n;

    double arr[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> arr[i];
    }

    cout << "\nSum: " << findSum(arr, n) << endl;
    cout << "Average: " << findAverage(arr, n) << endl;
    cout << "Maximum: " << findMax(arr, n) << endl;
    cout << "Minimum: " << findMin(arr, n) << endl;

    return 0;
}
