#include <iostream>
#include <vector>
#include "../include/User.h"
#include "../include/Student.h"

using namespace std;

struct AuthSystem {
    vector<Student> students;

    Student* findStudent(const string& username) {
        for (auto& s : students) {
            if (s.getUsername() == username) return &s;
        }
        return nullptr;
    }

    Student& signup(const string& username,
                    const string& password,
                    const string& email,
                    const string& name,
                    const string& studentID,
                    const string& major,
                    double gpa) {
        if (findStudent(username)) {
            throw runtime_error("Username already exists");
        }
        string userID = "U" + to_string(students.size() + 1); // simple placeholder
        students.emplace_back(username, password, email, name, userID, studentID, major, gpa);
        return students.back();
    }

    Student* login(const string& username, const string& password) {
        Student* s = findStudent(username);
        if (s && s->getPassword() == password) return s;
        return nullptr;
    }
};

static string prompt(const string& label) {
    cout << label;
    string value;
    getline(cin, value);
    return value;
}

static void studentSession(Student& student) {
    bool inSession = true;
    User* userPtr = &student;  // runtime polymorphism
    while (inSession) {
        userPtr->displayMenu(); // calls Student::displayMenu
        string choice;
        getline(cin, choice);

        if (choice == "1") {
            student.displayStudentInfo();
        } else if (choice == "2") {
            student.displayEnrolledCourses();
        } else if (choice == "3") {
            inSession = false;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    }
}

int main() {
    AuthSystem auth;
    bool running = true;

    while (running) {
        cout << "\n=====================================\n";
        cout << "  University Auth (Member 1 Scope)\n";
        cout << "=====================================\n";
        cout << "1. Sign up (Student)\n";
        cout << "2. Login (Student)\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";

        string choice;
        getline(cin, choice);

        try {
            if (choice == "1") {
                cout << "\n--- Sign Up ---\n";
                string username = prompt("Username: ");
                string password = prompt("Password: ");
                string email = prompt("Email: ");
                string name = prompt("Full Name: ");
                string studentID = prompt("Student ID: ");
                string major = prompt("Major: ");
                double gpa = 0.0;
                try {
                    gpa = stod(prompt("GPA (number): "));
                } catch (...) {
                    gpa = 0.0;
                }
                Student& s = auth.signup(username, password, email, name, studentID, major, gpa);
                cout << "Student account created for " << s.getName() << ". You can now log in.\n";
            } else if (choice == "2") {
                cout << "\n--- Login ---\n";
                string username = prompt("Username: ");
                string password = prompt("Password: ");
                Student* s = auth.login(username, password);
                if (!s) {
                    cout << "Invalid username or password.\n";
                } else {
                    cout << "Welcome, " << s->getName() << "!\n";
                    studentSession(*s);
                }
            } else if (choice == "3") {
                running = false;
            } else {
                cout << "Invalid option. Try again.\n";
            }
        } catch (const exception& ex) {
            cout << "Error: " << ex.what() << endl;
        }
    }

    cout << "Goodbye!\n";
    return 0;
}