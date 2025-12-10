#include "Admin.h"

Admin::Admin() : User() {}
Admin::Admin(std::string username)
    : User(username, "Admin") {}

// Student creation
Student Admin::createStudent(std::string name, std::string id) {
    return Student(name, id);
}

bool Admin::deleteStudent(std::vector<Student>& students, std::string id) {
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {
            students.erase(students.begin() + i);
            return true;
        }
    }
    return false;
}

// Courses
Course Admin::createCourse(std::string id, std::string title, int credit) {
    return Course(id, title, credit);
}

bool Admin::deleteCourse(std::vector<Course>& courses, std::string id) {
    for (size_t i = 0; i < courses.size(); i++) {
        if (courses[i].getCourseID() == id) {
            courses.erase(courses.begin() + i);
            return true;
        }
    }
    return false;
}

bool Admin::updateCourse(std::vector<Course>& courses, Course updated) {
    for (auto& c : courses) {
        if (c.getCourseID() == updated.getCourseID()) {
            c = updated;
            return true;
        }
    }
    return false;
}

// View students enrolled in a course
std::vector<Student> Admin::getStudentsInCourse(
    const std::vector<Registration>& reg,
    const std::vector<Student>& students,
    std::string courseID)
{
    std::vector<Student> enrolled;
    for (auto& r : reg) {
        if (r.getCourseID() == courseID) {
            for (auto& s : students) {
                if (s.getId() == r.getStudentID()) {
                    enrolled.push_back(s);
                }
            }
        }
    }
    return enrolled;
}
