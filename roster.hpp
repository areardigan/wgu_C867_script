//
//  roster.hpp
//  c867_project
//
//  Created by Andrew Reardigan on 1/5/24.
//

#ifndef roster_hpp
#define roster_hpp

#include <stdio.h>
#include "student.hpp"
#include <iostream>
#include <string>
#include <vector>

class Roster {
public:
    Roster();
    ~Roster();

    void add(const std::string& student_id, const std::string& first_name, const std::string& last_name,
             const std::string& email_address, int age, int daysInCourse1,
             int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(const std::string& student_id);
    void printAll() const;
    void printAverageDaysInCourse(const std::string& student_id) const;
    void printInvalidEmails() const;
    void printByDegreeProgram(DegreeProgram degree_program) const;
    std::string getStudentIDAt(int index) const;
private:
    Student* classRosterArray[5];
    int lastIndex;
};

#endif 
