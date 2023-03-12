/*
*****************************************************************************
                              College.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 12 March 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "College.h"
#include <iostream>
#include <iomanip>

namespace sdds {
    College::~College() {
        for(auto i = m_persons.begin(); i != m_persons.end(); i++) {
            delete *i;
        }
    }
    // Adds the address of the person object received as parameter into the m_persons vector
    College& College::operator+=(Person* thePerson) {
        m_persons.push_back(thePerson);
        return *this;
    }

    // Iterates over the persons stored in m_persons and prints their details
    void College::display(std::ostream& out) const {
        out << "------------------------------------------------------------------------------------------------------------------------" << '\n';
        out << "|                                        Test #1 Persons in the college!                                               |" << '\n';
        out << "------------------------------------------------------------------------------------------------------------------------" << '\n';

        for(auto i = m_persons.begin(); i != m_persons.end(); i++) {
            (*i)->display(out);
            out << std::endl;
        }

        out << "------------------------------------------------------------------------------------------------------------------------" << '\n';
        out << "|                                        Test #2 Persons in the college!                                               |" << '\n';
        out << "------------------------------------------------------------------------------------------------------------------------" << '\n';

        for(auto i = m_persons.begin(); i != m_persons.end(); i++) {
            out << std::left;
            out << "| " << std::setw(10) << (*i)->status() << "| ";
            out << std::setw(10) << (*i)->id() << "| ";
            out << std::setw(20) << (*i)->name() << " | ";
            out << std::setw(3) << (*i)->age() << " |";
            out << std::endl;
        }

        out << "------------------------------------------------------------------------------------------------------------------------" << '\n';
    }
}