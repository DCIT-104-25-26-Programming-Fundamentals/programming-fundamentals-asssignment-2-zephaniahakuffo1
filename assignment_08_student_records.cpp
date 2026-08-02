// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's name, ID, and average score.
//
//   3. Search for a Student by ID
//      - Ask the user for a student ID.
//      - If found, display that student's full details including all scores.
//      - If not found, print a message saying so.
//
//   4. Exit
//
// -----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

const int MAX_STUDENTS = 50;
Student students[MAX_STUDENTS];
int studentCount = 0;

double getAverage(Student s) {
    if (s.scores.empty()) return 0;
    double sum = 0;
    for (int i = 0; i < s.scores.size(); i++) {
        sum += s.scores[i];
    }
    return sum / s.scores.size();
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Cannot add more students." << endl;
        return;
    }

    Student s;
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, s.name);

    cout << "Enter student ID: ";
    cin >> s.id;

    int numScores;
    cout << "How many scores to enter? ";
    cin >> numScores;

    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;
        s.scores.push_back(score);
    }

    students[studentCount] = s;
    studentCount++;
    cout << "Student added successfully!" << endl;
}

void displayAllStudents() {
    if (studentCount == 0) {
        cout << "No students on record." << endl;
        return;
    }

    cout << "\n--- Student Records ---" << endl;
    cout << "Name\t\t\tID\t\tAverage" << endl;
    cout << "-----------------------------------------------" << endl;
    for (int i = 0; i < studentCount; i++) {
        cout << students[i].name << "\t\t" << students[i].id << "\t\t" << getAverage(students[i]) << endl;
    }
}

void searchStudent() {
    int searchId;
    cout << "Enter student ID to search: ";
    cin >> searchId;

    bool found = false;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == searchId) {
            cout << "\nName: " << students[i].name << endl;
            cout << "ID: " << students[i].id << endl;
            cout << "Scores: ";
            for (int j = 0; j < students[i].scores.size(); j++) {
                cout << students[i].scores[j];
                if (j < students[i].scores.size() - 1) cout << ", ";
            }
            cout << endl;
            cout << "Average: " << getAverage(students[i]) << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with ID " << searchId << " not found." << endl;
    }
}

int main() {
    int choice;
    cout << "=== Student Record System ===" << endl;

    do {
        cout << "\n1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Search by ID" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            addStudent();
        } else if (choice == 2) {
            displayAllStudents();
        } else if (choice == 3) {
            searchStudent();
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
        } else {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 4);

    return 0;
}
