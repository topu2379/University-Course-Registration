#include "../include/User.h"
#include <iostream>
using namespace std;

// Default Constructor
User::User() {
    username = "";
    password = "";
    email = "";
    name = "";
    userID = "";
}

// Parameterized Constructor
User::User(string username, string password, string email, string name, string userID) {
    this->username = username;
    this->password = password;
    this->email = email;
    this->name = name;
    this->userID = userID;
}

// Destructor
User::~User() {
    // Nothing to clean up for now
}

// Getters
string User::getUsername() const {
    return username;
}

string User::getPassword() const {
    return password;
}

string User::getEmail() const {
    return email;
}

string User::getName() const {
    return name;
}

string User::getUserID() const {
    return userID;
}

// Setters
void User::setUsername(string username) {
    this->username = username;
}

void User::setPassword(string password) {
    this->password = password;
}

void User::setEmail(string email) {
    this->email = email;
}

void User::setName(string name) {
    this->name = name;
}

// Display user information
void User::displayInfo() const {
    cout << "\n=====================================" << endl;
    cout << "       USER INFORMATION              " << endl;
    cout << "=====================================" << endl;
    cout << "Name: " << name << endl;
    cout << "Username: " << username << endl;
    cout << "Email: " << email << endl;
    cout << "User ID: " << userID << endl;
    cout << "=====================================\n" << endl;
}