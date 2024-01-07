//
//  roster.cpp
//  c867_project
//
//  Created by Andrew Reardigan on 1/5/24.
//

#include "roster.hpp"
#include <iostream>
#include <array>
#include <cmath>

// Roster constructor initializing the lastIndex to indicate an empty array.
Roster::Roster() : lastIndex(-1) {
    // Initialize the classRosterArray pointers to nullptr.
    for (int i = 0; i < 5; ++i) {
        classRosterArray[i] = nullptr;
    }
}

// Roster destructor to deallocate memory used by Student objects.
Roster::~Roster() {
    // Delete all Student objects created dynamically.
    for (int i = 0; i <= lastIndex; ++i) {
        delete classRosterArray[i];
    }
}

// Add a new Student to the Roster.
void Roster::add(const std::string& studentID, const std::string& firstName, const std::string& lastName,
                 const std::string& emailAddress, int age, int daysInCourse1,
                 int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    std::array<int, 3> daysInCourse = {daysInCourse1, daysInCourse2, daysInCourse3};
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
}

// Remove a Student from the Roster based on studentID.
void Roster::remove(const std::string& studentID) {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i] && classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;

            // Shift the rest of the elements to the left
            for (int j = i; j < lastIndex; j++) {
                classRosterArray[j] = classRosterArray[j + 1];
            }
            classRosterArray[lastIndex] = nullptr;
            lastIndex--;
            return;
        }
    }
    std::cout << "Student ID " << studentID << " not found." << std::endl;
}

void Roster::printAll() const {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]) {
            classRosterArray[i]->print();
        }
    }
}

// Print average days in course for a student.
void Roster::printAverageDaysInCourse(const std::string& studentID) const {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i] && classRosterArray[i]->getStudentID() == studentID) {
            auto days = classRosterArray[i]->getDaysInCourse();
            double average = (days[0] + days[1] + days[2]) / 3.0;
            std::cout << "Student ID: " << studentID << ", average days in course is:  "
                      << std::round(average)  << std::endl;
            return;
        }
    }
    std::cout << "The student with the ID: " << studentID << " was not found." << std::endl;
}

void Roster::printInvalidEmails() const {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]) {
            std::string email = classRosterArray[i]->getEmailAddress();
            if (email.find('@') == std::string::npos || email.find('.') == std::string::npos || email.find(' ') != std::string::npos) {
                std::cout << "Invalid email: " << email << std::endl;
            }
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i] && classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}
std::string Roster::getStudentIDAt(int index) const {
    if (index >= 0 && index <= lastIndex && classRosterArray[index] != nullptr) {
        return classRosterArray[index]->getStudentID();
    } else {
        return ""; // Return an empty string if index is out of bounds or the student does not exist
    }
}
