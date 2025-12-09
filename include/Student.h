#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include <vector>
using namespace std;

// Student class inherits from User
class Student : public User {
private:
    string studentID;
    string major;
    double gpa;
    vector<string> enrolledCourses;  // List of course codes student is enrolled in

public:
    // Constructors
    Student();
    Student(string username, string password, string email, string name, 
            string userID, string studentID, string major, double gpa);
    
    // Destructor
    ~Student();
    
    // Getters
    string getStudentID() const;
    string getMajor() const;
    double getGPA() const;
    vector<string> getEnrolledCourses() const;
    
    // Setters
    void setStudentID(string studentID);
    void setMajor(string major);
    void setGPA(double gpa);
    void setEnrolledCourses(const vector<string>& courses);
    
    // Course management
    void addCourse(string courseCode);
    void removeCourse(string courseCode);
    bool isEnrolledIn(string courseCode) const;
    int getTotalEnrolledCourses() const;
    
    // Override virtual functions from User (Polymorphism!)
    void displayMenu() override;
    string getUserType() const override;
    
    // Student-specific display
    void displayStudentInfo() const;
    void displayEnrolledCourses() const;
};

#endif