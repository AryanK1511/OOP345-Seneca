/*
*****************************************************************************
                              Professor.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 12 March 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_PROFESSOR_H
#define SDDS_PROFESSOR_H

#include "Employee.h"
#include <iostream>

namespace sdds {
    class Professor : public Employee {
    private:
        std::string m_department {};
    public:
        Professor() = default;
        // Calls the constructor from Employee to build the sub-object
        Professor(std::istream& in);
        // Calls Employee::display() to print the information about the Employee, and adds department|"Professor" at the end
        void display(std::ostream& out) const;
        // A query that returns word Professor
        std::string status() const;
        // A query that returns the department
        std::string department() const;
    };
}

#endif // SDDS_PROFESSOR_H