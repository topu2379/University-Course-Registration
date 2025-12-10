#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Admin.h"
#include <vector>
#include <string>

using namespace std;

// FileManager handles Admin user data persistence
// Note: Student and Course file I/O is handled by RegistrationSystem
class FileManager {
private:
    string adminsFilePath;

public:
    // Constructor
    FileManager(const string& adminsFilePath);
    
    // Save all admins to file
    void saveAdmins(const vector<Admin>& admins) const;
    
    // Load all admins from file
    vector<Admin> loadAdmins() const;
    
    // Append a single admin to file
    void appendAdmin(const Admin& admin) const;
    
    // Check if admin file exists
    bool fileExists() const;
};

#endif 
