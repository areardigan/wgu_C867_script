//
//  student.hpp
//  c867_project
//
//  Created by Andrew Reardigan on 1/5/24.
//


#include <stdio.h>

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <array>
#include "degree.hpp"

class Student {
public:
    // Constructor to initialize a student object with data.
    Student(const std::string& student_id, const std::string& first_name, const std::string& lastName,
            const std::string& email_address, int age, const std::array<int, 3>& course_avg,
            DegreeProgram degree_program);

    // Getters for student
    std::string getStudentID() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmailAddress() const;
    int getAge() const;
    std::array<int, 3> getDaysInCourse() const;
    DegreeProgram getDegreeProgram() const;

    // Setters for student
    void setStudentID(const std::string& id);
    void setFirstName(const std::string& first_name);
    void setLastName(const std::string& lastName);
    void setEmailAddress(const std::string& email);
    void setAge(int age);
    void setDaysInCourse(const std::array<int, 3>& days);
    void setDegreeProgram(DegreeProgram degree_program);
    std::string degreeProgramToString(DegreeProgram dp) const;
    void print() const;

private:
    //private vs public. set all private that modify actual objs.
    std::string student_id;
    std::string first_name;
    std::string last_name;
    std::string email_address;
    int age;
    std::array<int, 3> days_in_course;
    DegreeProgram degree_program;
};

#endif /* STUDENT_HPP */
