#include "FileManager.h"
#include <fstream>
#include <sstream>

// Users
void FileManager::saveUsers(const std::vector<User>& users) {
    std::ofstream file(usersFile);
    for (auto& u : users) file << u.serialize() << "\n";
}

std::vector<User> FileManager::loadUsers() {
    std::vector<User> users;
    std::ifstream file(usersFile);
    std::string line;

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string name, role;
        getline(ss, name, ',');
        getline(ss, role, ',');
        users.emplace_back(name, role);
    }
    return users;
}

// Students
void FileManager::saveStudents(const std::vector<Student>& students) {
    std::ofstream file(studentsFile);
    for (auto& s : students) file << s.serialize() << "\n";
}

std::vector<Student> FileManager::loadStudents() {
    std::vector<Student> list;
    std::ifstream file(studentsFile);
    std::string line;

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string name, id;
        getline(ss, name, ',');
        getline(ss, id, ',');
        list.emplace_back(name, id);
    }
    return list;
}

// Courses
void FileManager::saveCourses(const std::vector<Course>& courses) {
    std::ofstream file(coursesFile);
    for (auto& c : courses) file << c.serialize() << "\n";
}

std::vector<Course> FileManager::loadCourses() {
    std::vector<Course> list;
    std::ifstream file(coursesFile);
    std::string line;

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string id, title, creditStr;
        getline(ss, id, ',');
        getline(ss, title, ',');
        getline(ss, creditStr, ',');
        list.emplace_back(id, title, stoi(creditStr));
    }
    return list;
}

// Registrations
void FileManager::saveRegistrations(const std::vector<Registration>& reg) {
    std::ofstream file(registrationFile);
    for (auto& r : reg) file << r.serialize() << "\n";
}

std::vector<Registration> FileManager::loadRegistrations() {
    std::vector<Registration> list;
    std::ifstream file(registrationFile);
    std::string line;

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string sid, cid;
        getline(ss, sid, ',');
        getline(ss, cid, ',');
        list.emplace_back(sid, cid);
    }
    return list;
}
