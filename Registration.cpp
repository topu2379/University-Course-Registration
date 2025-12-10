#include "Registration.h"

Registration::Registration() : studentID(""), courseID("") {}

Registration::Registration(std::string s, std::string c)
    : studentID(s), courseID(c) {}

std::string Registration::getStudentID() const { return studentID; }
std::string Registration::getCourseID() const { return courseID; }

std::string Registration::serialize() const {
    return studentID + "," + courseID;
}