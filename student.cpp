//
//  student.cpp
//  c867_project
//
//  Created by Andrew Reardigan on 1/5/24.
//


#include "student.hpp"
#include <iostream>



Student::Student(const std::string& studentID, const std::string& firstName, const std::string& lastName,
                 const std::string& emailAddress, int age, const std::array<int, 3>& daysInCourse,
                 DegreeProgram degreeProgram)
    : student_id(studentID), first_name(firstName), last_name(lastName),
      email_address(emailAddress), age(age), days_in_course(daysInCourse),
      degree_program(degreeProgram) {}

// Getters
std::string Student::getStudentID() const { return student_id; }
std::string Student::getFirstName() const { return first_name; }
std::string Student::getLastName() const { return last_name; }
std::string Student::getEmailAddress() const { return email_address; }
int Student::getAge() const { return age; }
std::array<int, 3> Student::getDaysInCourse() const { return days_in_course; }
DegreeProgram Student::getDegreeProgram() const { return degree_program; }

// Setters
void Student::setStudentID(const std::string& id) { student_id = id; }
void Student::setFirstName(const std::string& firstName) { first_name = firstName; }
void Student::setLastName(const std::string& lastName) { last_name = lastName; }
void Student::setEmailAddress(const std::string& email) { email_address = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInCourse(const std::array<int, 3>& days) { days_in_course = days; }
void Student::setDegreeProgram(DegreeProgram degreeProgram) { degree_program = degreeProgram; }


std::string Student::degreeProgramToString(DegreeProgram dp) const {
    switch(dp) {
        case SECURITY: return "SECURITY";
        case NETWORK: return "NETWORK";
        case SOFTWARE: return "SOFTWARE";
        default: return "UNDEFINED";
    }
}

void Student::print() const {

    std::cout << student_id << "\t"
            << first_name << "\t"
            << last_name << "\t"
            << email_address << "\t"
            << age << "\t"
            << "{" << days_in_course[0] << ", "
            << days_in_course[1] << ", " << days_in_course[2] << "}\t"
    << degreeProgramToString(getDegreeProgram()) << std::endl;
}
