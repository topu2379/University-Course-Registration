#include "User.h"
#include <iostream>
using namespace std;

User::User() : username(""), role("User") {}

User::User(string username, string role)
    : username(username), role(role) {}

string User::getUsername() const { return username; }
string User::getRole() const { return role; }

void User::displayInfo() const {
    cout << "Username: " << username << endl;
    cout << "Role: " << role << endl;
}

string User::serialize() const {
    return username + "," + role;
}
