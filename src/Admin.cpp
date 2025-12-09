#include "Admin.h"
#include "RegistrationException.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

// Constructors
Admin::Admin() : User() {}

Admin::Admin(string id, string name, string email, string password) 
    : User(id, name, email, password, "Admin") {}

// POLYMORPHISM: Override displayInfo
void Admin::displayInfo() const {
    cout << "\n========================================\n";
    cout << "          ADMIN INFORMATION            \n";
    cout << "========================================\n";
    cout << "ID:       " << userId << endl;
    cout << "Name:     " << userName << endl;
    cout << "Email:    " << email << endl;
    cout << "Role:     " << role << endl;
    cout << "========================================\n";
}

// Add a new course to the system
void Admin::addCourse(vector<Course>& courses, const Course& newCourse) {
    // Check if course code already exists
    for (const auto& course : courses) {
        if (course.getCourseCode() == newCourse.getCourseCode()) {
            throw RegistrationException("Course code already exists: " + newCourse.getCourseCode());
        }
    }
    
    courses.push_back(newCourse);
    cout << "\n✓ Course added successfully: " << newCourse.getCourseCode() 
         << " - " << newCourse.getCourseName() << endl;
}

// Remove a course from the system
bool Admin::removeCourse(vector<Course>& courses, const string& courseCode) {
    auto it = remove_if(courses.begin(), courses.end(),
        [&courseCode](const Course& c) {
            return c.getCourseCode() == courseCode;
        });
    
    if (it != courses.end()) {
        courses.erase(it, courses.end());
        cout << "\n✓ Course removed successfully: " << courseCode << endl;
        return true;
    }
    
    throw RegistrationException("Course not found: " + courseCode);
}

// Modify an existing course
bool Admin::modifyCourse(vector<Course>& courses, const string& courseCode) {
    // Find the course
    Course* courseToModify = nullptr;
    for (auto& course : courses) {
        if (course.getCourseCode() == courseCode) {
            courseToModify = &course;
            break;
        }
    }
    
    if (!courseToModify) {
        throw RegistrationException("Course not found: " + courseCode);
    }
    
    cout << "\n=== Modify Course: " << courseCode << " ===\n";
    cout << "Current course name: " << courseToModify->getCourseName() << endl;
    
    int choice;
    cout << "\nWhat would you like to modify?\n";
    cout << "1. Course Name\n";
    cout << "2. Credits\n";
    cout << "3. Capacity\n";
    cout << "4. Schedule (Day and Time)\n";
    cout << "0. Cancel\n";
    cout << "Choice: ";
    cin >> choice;
    cin.ignore();
    
    switch (choice) {
        case 1: {
            string newName;
            cout << "Enter new course name: ";
            getline(cin, newName);
            courseToModify->setCourseName(newName);
            cout << "✓ Course name updated.\n";
            break;
        }
        case 2: {
            int newCredits;
            cout << "Enter new credits: ";
            cin >> newCredits;
            courseToModify->setCredits(newCredits);
            cout << "✓ Credits updated.\n";
            break;
        }
        case 3: {
            int newCapacity;
            cout << "Enter new capacity: ";
            cin >> newCapacity;
            courseToModify->setCapacity(newCapacity);
            cout << "✓ Capacity updated.\n";
            break;
        }
        case 4: {
            string newDay, newStartTime, newEndTime;
            cout << "Enter new day (e.g., Monday): ";
            getline(cin, newDay);
            cout << "Enter new start time (HH:MM): ";
            getline(cin, newStartTime);
            cout << "Enter new end time (HH:MM): ";
            getline(cin, newEndTime);
            
            courseToModify->setSchedule(newDay, newStartTime, newEndTime);
            cout << "✓ Schedule updated.\n";
            break;
        }
        case 0:
            cout << "Modification cancelled.\n";
            return false;
        default:
            cout << "Invalid choice.\n";
            return false;
    }
    
    return true;
}

// View all courses in the system
void Admin::viewAllCourses(const vector<Course>& courses) const {
    if (courses.empty()) {
        cout << "\nNo courses available in the system.\n";
        return;
    }
    
    cout << "\n========================================\n";
    cout << "          ALL COURSES IN SYSTEM        \n";
    cout << "========================================\n";
    
    for (const auto& course : courses) {
        course.displayCourseInfo();
        cout << "----------------------------------------\n";
    }
    
    cout << "Total Courses: " << courses.size() << endl;
}

// View students enrolled in a specific course
void Admin::viewCourseEnrollments(const string& courseCode) const {
    cout << "\n=== Enrollments for Course: " << courseCode << " ===\n";
    cout << "(This requires integration with RegistrationSystem)\n";
    // This will be implemented when integrated with RegistrationSystem
}

// Serialize admin data for file I/O
string Admin::serialize() const {
    // Format: userId,userName,email,password,role
    return userId + "," + userName + "," + email + "," + password + "," + role;
}