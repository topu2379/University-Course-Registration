#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

// Abstract Base Class for all users
class User {
protected:
    string username;
    string password;
    string email;
    string name;
    string userID;

public:
    // Constructor
    User();
    User(string username, string password, string email, string name, string userID);
    
    // Virtual Destructor (important for base classes)
    virtual ~User();
    
    // Getters
    string getUsername() const;
    string getPassword() const;
    string getEmail() const;
    string getName() const;
    string getUserID() const;
    
    // Setters
    void setUsername(string username);
    void setPassword(string password);
    void setEmail(string email);
    void setName(string name);
    
    // Virtual functions (to be overridden by derived classes)
    virtual void displayMenu() = 0;  // Pure virtual - makes User abstract
    virtual string getUserType() const = 0;  // Returns "STUDENT" or "ADMIN"
    
    // Display user info
    void displayInfo() const;
};

#endif


