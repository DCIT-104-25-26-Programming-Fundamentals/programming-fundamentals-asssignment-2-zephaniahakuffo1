// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which number to delete and remove it.
//
//   4. Exit
//      - Exit the program cleanly.
//
// -----------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

const int MAX_TASKS = 100;
string tasks[MAX_TASKS];
int taskCount = 0;

void addTask() {
    if (taskCount >= MAX_TASKS) {
        cout << "Task list is full!" << endl;
        return;
    }
    string task;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, task);
    tasks[taskCount] = task;
    taskCount++;
    cout << "Task added successfully!" << endl;
}

void viewTasks() {
    if (taskCount == 0) {
        cout << "Your to-do list is empty." << endl;
        return;
    }
    cout << "\n--- Your Tasks ---" << endl;
    for (int i = 0; i < taskCount; i++) {
        cout << (i + 1) << ". " << tasks[i] << endl;
    }
    cout << "------------------" << endl;
}

void deleteTask() {
    if (taskCount == 0) {
        cout << "No tasks to delete." << endl;
        return;
    }
    viewTasks();
    int num;
    cout << "Enter task number to delete: ";
    cin >> num;

    if (num < 1 || num > taskCount) {
        cout << "Invalid task number." << endl;
        return;
    }

    for (int i = num - 1; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    taskCount--;
    cout << "Task deleted successfully!" << endl;
}

int main() {
    int choice;

    cout << "=== To-Do List ===" << endl;

    do {
        cout << "\n1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            addTask();
        } else if (choice == 2) {
            viewTasks();
        } else if (choice == 3) {
            deleteTask();
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
