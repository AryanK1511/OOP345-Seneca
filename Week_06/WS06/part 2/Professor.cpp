/*
*****************************************************************************
                              Professor.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 12 March 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Professor.h"
#include <iostream>
using std::cout;
using std::endl;

namespace sdds {
    // Calls the constructor from Employee to build the sub-object
    Professor::Professor(std::istream& in) : Employee(in) {
        m_department = Employee::m_dept;
    }

    // Calls Employee::display() to print the information about the Employee, and adds department|"Professor" at the end
    void Professor::display(std::ostream& out) const {
        Employee::display(out);
        out << m_department;
        out << "| Professor";
    }

    // A query that returns word Professor
    std::string Professor::status() const { return "Professor"; }

    // A query that returns the department
    std::string Professor::department() const { return m_department; }
}