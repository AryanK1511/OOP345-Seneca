/*
*****************************************************************************
                              Utilities.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 12 March 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include "Person.h"
#include <iostream>

namespace sdds {
    // Creates instances on the Person hierarchy
    Person* buildInstance(std::istream& in);
}

#endif // SDDS_UTILITIES_H