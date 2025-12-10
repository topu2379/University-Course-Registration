#include "Course.h"

Course::Course() : courseID(""), title(""), credit(0) {}

Course::Course(std::string id, std::string title, int credit)
    : courseID(id), title(title), credit(credit) {}

std::string Course::getCourseID() const { return courseID; }
std::string Course::getTitle() const { return title; }
int Course::getCredit() const { return credit; }

std::string Course::serialize() const {
    return courseID + "," + title + "," + std::to_string(credit);
}
