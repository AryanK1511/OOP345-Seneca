#include "Student.h"
#include <iostream>
using std::cout;
using std::endl;

#include <iostream>
#include <iomanip>

namespace sdds {
    // Read a single record from the stream, extract all the information about a single student and store it in the attributes
    Student::Student(std::istream& is) {

    }

    // A query that returns the id of the employee
    std::string Student::id() const { return m_id; }

    // A query that returns the age of the employee
    std::string Student::age() const { return m_age; }

    // A query that returns the string Student
    std::string Student::status() const { return "Student"; }

    // A query that returns the name of the student
    std::string Student::name() const { return m_name; }

    // A query that inserts in the first parameter the content of the student object
    void Student::display(std::ostream& out) const {
        out << "| " << std::left << "Student"
            << "| " << std::setw(10) << std::left << m_id
            << "| " << std::setw(20) << std::left << m_name
            << "| " << std::setw(3) << std::left << m_age
            << "| " << m_courses[0] << "\n";
    }
}