/*
*****************************************************************************
                              Database.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 21 March 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_DATABASE_H
#define SDDS_DATABASE_H

#include <iostream>
#include <memory>

namespace sdds {
    // Global variable that holds the maximum amount of entries possible
    const size_t max_entries {20};

    enum class Err_Status
    {
        Err_Success,
        Err_NotFound,
        Err_OutOfMemory,
    };

    class Database {
    private:
        inline static std::shared_ptr<Database> m_database {};
        size_t m_entries;
        std::string m_keys[20] {};
        std::string m_values[20] {};
        std::string m_filename;
        Database(const std::string& filename);
        // Strips all the not required characters from a string
        std::string strip(const std::string& str);
    public:
        // Returns or creates an instance of type Database
        static std::shared_ptr<Database> getInstance(const std::string& filename);
        // A query that searches in the array of keys for the first parameter
        Err_Status GetValue(const std::string& key, std::string& value);
        //  If there is space in the database, the key/value pair is added
        Err_Status SetValue(const std::string& key, const std::string& value);
        // Destructor
        ~Database();
    };
}

#endif // SDDS_DATABASE_H