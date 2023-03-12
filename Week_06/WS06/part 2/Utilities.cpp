/*
*****************************************************************************
                              Utilities.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 12 March 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Utilities.h"
#include "Employee.h"
#include "Student.h"
#include "Professor.h"
#include <iostream>

namespace sdds {
    // Creates instances on the Person hierarchy
    Person* buildInstance(std::istream& in) {
        char tag {};
        in >> tag;

        if (tag == 's' || tag == 'S') {
            return new Student(in);
        }

        if (tag == 'p' || tag == 'P') {
            return new Professor(in);
        }

        if (tag == 'e' || tag == 'E') {
            return new Employee(in);
        }

        // Ignoring the rest of the string
        in.ignore(1000, '\n');
        return nullptr;
    }
}