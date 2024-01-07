//
//  main.cpp
//  c867_project
//
//  Created by Andrew Reardigan on 1/5/24.
//

#include <iostream>
#include <string>
#include <sstream>
#include "roster.hpp"

using namespace std;

DegreeProgram parseDegreeProgram(const string& degreeString) {
    if (degreeString == "SECURITY") return SECURITY;
    if (degreeString == "NETWORK") return NETWORK;
    if (degreeString == "SOFTWARE") return SOFTWARE;
    return SOFTWARE; // Default case
}

void parseAndAddStudent(Roster& roster, const string& studentData) {
    istringstream ss(studentData);
    string token;
    vector<string> tokens;

    while (getline(ss, token, ',')) {
        tokens.push_back(token);
    }

    string student_id = tokens[0];
    string first_name = tokens[1];
    string last_name = tokens[2];
    string email = tokens[3];
    int age = stoi(tokens[4]);
    int course_1_avg = stoi(tokens[5]);
    int course_2_avg = stoi(tokens[6]);
    int course_3_avg = stoi(tokens[7]);
    DegreeProgram degree_program = parseDegreeProgram(tokens[8]);

    roster.add(student_id, first_name, last_name, email, age, course_1_avg, course_2_avg, course_3_avg, degree_program);
}

int main() {
    std::cout << "C867-Scripting & Programming:Applications" << std::endl;
    std::cout << "Language: C++" << std::endl;
    std::cout << "Student ID: 011352471" << std::endl;
    std::cout << "Name: Andrew Reardigan" << std::endl;
    std::cout << " "<< std::endl;

    Roster classRoster;

    const string student_data[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Andrew,Reardigan,areardi@wgu.edu,33,2,5,147,SOFTWARE"
    };

    for (const string& data : student_data) {
        parseAndAddStudent(classRoster, data);
    }

    // Print all students
    std::cout << "Displaying all students:" << std::endl;
    //attempt to add quick header to table
//    std::cout << "id\tfirst\tlast\temail\t\t\t\tage\tdays_in_courses\tprogram" << std::endl;
    classRoster.printAll();
    std::cout << " "<< std::endl;

    // Print invalid emails
    std::cout << "Displaying invalid emails:" << std::endl;
    std::cout << " "<< std::endl;
    classRoster.printInvalidEmails();
    std::cout << " "<< std::endl;

    // Print average days in course
    for (int i = 0; i < 5; ++i) {
        string studentID = classRoster.getStudentIDAt(i);
        classRoster.printAverageDaysInCourse(studentID);
    }
    std::cout << " "<< std::endl;
    // Print students by degree program
    std::cout << "Showing students in degree program: SOFTWARE" << std::endl;
    std::cout << " "<< std::endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    std::cout << " "<< std::endl;

    // Remove a student and print all again
    std::cout << "Removing A3: "<< std::endl;
    std::cout << " "<< std::endl;
    classRoster.remove("A3");
    classRoster.printAll();
    std::cout << " "<< std::endl;
    
    // Attempt to remove the same student again
    std::cout << "Removing A3 again "<< std::endl;
    std::cout << " "<< std::endl;
    classRoster.remove("A3");
    
    
    std::cout << "DONE "<< std::endl;

    return 0;
}
