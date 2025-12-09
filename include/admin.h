#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Course.h"
#include <vector>
#include <string>

using namespace std;

// Admin class - demonstrates INHERITANCE and POLYMORPHISM
class Admin : public User {
public:
    // Constructor
    Admin();
    Admin(string id, string name, string email, string password);

    // POLYMORPHISM: Override base class function
    void displayInfo() const override;
    
    // Admin-specific course management functions
    void addCourse(vector<Course>& courses, const Course& newCourse);
    bool removeCourse(vector<Course>& courses, const string& courseCode);
    bool modifyCourse(vector<Course>& courses, const string& courseCode);
    void viewAllCourses(const vector<Course>& courses) const;
    
    // View enrolled students in a specific course
    void viewCourseEnrollments(const string& courseCode) const;
    
    // Serialize for file I/O
    string serialize() const override;
};

#endif // ADMIN_H