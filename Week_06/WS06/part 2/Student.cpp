#include "Student.h"
#include <iostream>
using std::cout;
using std::endl;

#include <iostream>
#include <iomanip>

namespace sdds {
    // Read a single record from the stream, extract all the information about a single student and store it in the attributes
    Student::Student(std::istream& is) {
        std::string data {};
        is.ignore(1);

        std::getline(is, data);
        size_t startIndex {0};
        size_t endIndex = data.find(',');

        // Getting the name and storing it
        m_name = data.substr(startIndex, (endIndex - startIndex));
        startIndex = endIndex + 1;
        endIndex = data.find(',', startIndex);
        m_name.erase(0, m_name.find_first_not_of(" \t\r\n"));
        m_name.erase(m_name.find_last_not_of(" \t\r\n") + 1);

        // Getting the age and storing it
        m_age = data.substr(startIndex, (endIndex - startIndex));
        startIndex = endIndex + 1;
        endIndex = data.find(',', startIndex);
        m_age.erase(0, m_age.find_first_not_of(" \t\r\n"));
        m_age.erase(m_age.find_last_not_of(" \t\r\n") + 1);

        // Validating the age
        for (auto& ch: m_age) {
            if (std::isdigit(ch) == 0) {
                throw m_name + "++Invalid record!";
            }
        }

        // Getting the id and storing it
        m_id = data.substr(startIndex, (endIndex - startIndex));
        startIndex = endIndex + 1;
        endIndex = data.find(',', startIndex);
        m_id.erase(0, m_id.find_first_not_of(" \t\r\n"));
        m_id.erase(m_id.find_last_not_of(" \t\r\n") + 1);

        // Validating the employee id
        if (tolower(m_id[0]) != 's') {
            throw m_name + "++Invalid record!";
        }

        // Getting the number of courses and storing it
        m_count = data.substr(startIndex, (endIndex - startIndex));
        startIndex = endIndex + 1;
        endIndex = data.find(',', startIndex);
        m_count.erase(0, m_count.find_first_not_of(" \t\r\n"));
        m_count.erase(m_count.find_last_not_of(" \t\r\n") + 1);

        // Validating the count
        for (auto& ch: m_count) {
            if (std::isdigit(ch) == 0) {
                throw m_name + "++Invalid record!";
            }
        }

        // Getting the courses and storing them
        m_c = std::stoi(m_count);
        m_courses = new std::string[m_c];

        for (int i = 0; i < m_c; i++) {
            m_courses[i] = data.substr(startIndex, (endIndex - startIndex));
            startIndex = endIndex + 1;
            endIndex = data.find(',', startIndex);
            m_courses[i].erase(0, m_courses[i].find_first_not_of(" \t\r\n"));
            m_courses[i].erase(m_courses[i].find_last_not_of(" \t\r\n") + 1);
        }
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
        out << "| " << std::setw(10) << std::left << "Student"
            << "| " << std::setw(10) << std::left << m_id
            << "| " << std::setw(20) << std::left << m_name
            << " | " << std::setw(3) << std::left << m_age
            << " |" << m_courses[0];
            for (int i = 1; i < m_c; i++) {
                out << ", " << m_courses[i];
            }
    }

    Student::~Student() {
        delete[] m_courses;
    }
}