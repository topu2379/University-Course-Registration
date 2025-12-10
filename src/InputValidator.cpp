#include "../include/InputValidator.h"
#include <algorithm>
#include <cctype>

// Email validation - checks for basic email format
bool InputValidator::isValidEmail(const string& email) {
    if (email.empty()) return false;
    
    // Simple regex for email validation
    regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return regex_match(email, emailPattern);
}

// Student ID validation (S followed by 4-6 digits)
bool InputValidator::isValidStudentID(const string& studentID) {
    if (studentID.empty() || studentID[0] != 'S') return false;
    
    regex idPattern(R"(S\d{4,6})");
    return regex_match(studentID, idPattern);
}

// User ID validation (U followed by digits)
bool InputValidator::isValidUserID(const string& userID) {
    if (userID.empty() || userID[0] != 'U') return false;
    
    regex idPattern(R"(U\d+)");
    return regex_match(userID, idPattern);
}

// Course code validation (2-4 letters followed by 3 digits)
bool InputValidator::isValidCourseCode(const string& courseCode) {
    if (courseCode.empty()) return false;
    
    regex codePattern(R"([A-Z]{2,4}\d{3})");
    return regex_match(courseCode, codePattern);
}

// GPA validation (0.0 to 4.0)
bool InputValidator::isValidGPA(double gpa) {
    return gpa >= 0.0 && gpa <= 4.0;
}

// Time format validation (HH:MM)
bool InputValidator::isValidTimeFormat(const string& time) {
    if (time.length() != 5) return false;
    
    regex timePattern(R"(([0-1][0-9]|2[0-3]):[0-5][0-9])");
    return regex_match(time, timePattern);
}

// Day of week validation
bool InputValidator::isValidDayOfWeek(const string& day) {
    string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", 
                     "Friday", "Saturday", "Sunday"};
    
    for (const auto& validDay : days) {
        if (day == validDay) return true;
    }
    return false;
}

// Password validation (minimum 6 characters)
bool InputValidator::isValidPassword(const string& password) {
    return password.length() >= 6;
}

// Username validation (alphanumeric, 3-20 characters)
bool InputValidator::isValidUsername(const string& username) {
    if (username.length() < 3 || username.length() > 20) return false;
    
    regex usernamePattern(R"([a-zA-Z0-9_]+)");
    return regex_match(username, usernamePattern);
}

// Check if string is not empty (after trimming)
bool InputValidator::isNotEmpty(const string& input) {
    return !input.empty() && input.find_first_not_of(" \t\n\r") != string::npos;
}

// Check if string is a valid integer
bool InputValidator::isValidInteger(const string& input) {
    if (input.empty()) return false;
    
    size_t start = 0;
    if (input[0] == '-' || input[0] == '+') start = 1;
    
    if (start >= input.length()) return false;
    
    for (size_t i = start; i < input.length(); i++) {
        if (!isdigit(input[i])) return false;
    }
    return true;
}

// Check if string is a valid positive integer
bool InputValidator::isValidPositiveInteger(const string& input) {
    if (!isValidInteger(input)) return false;
    
    try {
        int value = stoi(input);
        return value > 0;
    } catch (...) {
        return false;
    }
}

// Validate capacity (1 to 500 seems reasonable)
bool InputValidator::isValidCapacity(int capacity) {
    return capacity > 0 && capacity <= 500;
}