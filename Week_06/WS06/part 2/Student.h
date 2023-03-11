#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H

#include "Person.h"
#include <iostream>

namespace sdds {
    class Student : public Person {
    private:
        std::string m_name {};
        std::string m_age {};
        std::string m_id {};
        std::string* m_courses { nullptr };
        size_t m_count { 0 };
    public:
        Student() = default;
        // Read a single record from the stream, extract all the information about a single student and store it in the attributes
        Student(std::istream& is);
        // Disabling Copy Operations
        Student(const Student&) = delete;
        Student& operator=(const Student&) = delete;
        // A query that returns the string Student
        std::string status() const;
        // A query that returns the name of the student
        std::string name() const;
        // A query that returns the id of the employee
        std::string id() const;
        // A query that returns the age of the employee
        std::string age() const;
        // A query that inserts in the first parameter the content of the student object
        void display(std::ostream& out = std::cout) const;
    };
}

#endif // SDDS_STUDENT_H