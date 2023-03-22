/*
*****************************************************************************
                              Database.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 21 March 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Database.h"
#include <fstream>
#include <iomanip>
#include <algorithm>

namespace sdds {
    // Private Constructor
    Database::Database(const std::string& filename) {
        m_filename = filename ;
        m_entries = 0 ;
        std::cout << "[" << this << "]" << " Database(const std::string&)" << std::endl;
        std::ifstream file(filename);
            std::string key {}, value {};
            while (file >> key >> value) {
                std::replace(key.begin(), key.end(), '_', ' '); // replace underscores with spaces
                SetValue(key, value);
            }
            file.close();
    }

    // Returns or creates an instance of type Database
    std::shared_ptr<Database> Database::getInstance(const std::string& filename) {
        return (m_database) ? m_database : m_database = std::shared_ptr<Database>(new Database(filename));
    }

    // A query that searches in the array of keys for the first parameter
    Err_Status Database::GetValue(const std::string& key, std::string& value) {
        Err_Status status { Err_Status::Err_NotFound };
        int flag = 0;
        for (size_t i = 0; i < m_entries && flag == 0; i++) {
            if (m_keys[i] == key) {
                value = m_values[i];
                status = Err_Status::Err_Success;
                flag = 1;
            }
        }
        return status;
    }

    //  If there is space in the database, the key/value pair is added
    Err_Status Database::SetValue(const std::string& key, const std::string& value) {
        Err_Status status { Err_Status::Err_OutOfMemory };
        if (m_entries < max_entries) {
            m_keys[m_entries] = key;
            m_values[m_entries] = value;
            m_entries++;
            status = Err_Status::Err_Success;
        }
        return status;
    }

    // Destructor
    Database::~Database() {
        std::cout << "[" << this << "]" << " ~Database()" << std::endl;
        std::ofstream databaseBackup(m_filename + ".bkp.txt");
        for (size_t i = { 0 }; i < m_entries; i++) {
            databaseBackup << std::left << std::setw(25) << m_keys[i] << " -> " << m_values[i] << std::endl;
        }
    }

    // Strips all the not required characters from a string
    std::string strip(const std::string& str) {
        std::string returnVal {};
        size_t first = str.find_first_not_of(" \t\r\n");
        size_t last = str.find_last_not_of(" \t\r\n");
        (std::string::npos == first) ? returnVal = str : returnVal = str.substr(first, (last - first + 1));
        return returnVal;
    }
}