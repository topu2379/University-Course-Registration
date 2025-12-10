#include "Student.h"

Student::Student() : name(""), id("") {}

Student::Student(std::string name, std::string id)
    : name(name), id(id) {}

std::string Student::getName() const { return name; }
std::string Student::getId() const { return id; }

std::string Student::serialize() const {
    return name + "," + id;
}
