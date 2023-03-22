/*
*****************************************************************************
                              Database.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 22 March 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_DATABASE_H
#define SDDS_DATABASE_H

#include <iostream>
#include <memory>
#include <fstream>
#include <iomanip>
#include <algorithm>

namespace sdds {
    // Global variable that holds the maximum amount of entries possible
    const size_t max_entries {20};

    enum class Err_Status
    {
        Err_Success,
        Err_NotFound,
        Err_OutOfMemory,
    };

    template <typename T>
    class Database {
    private:
        inline static std::shared_ptr<Database> m_database {};
        size_t m_entries;
        std::string m_keys[max_entries] {};
        T m_values[max_entries] {};
        std::string m_filename;

        // Private Constructor
        Database(const std::string& filename) {
            m_filename = filename;
            m_entries = 0;
            std::cout << "[" << this << "]" << " Database(const std::string&)" << std::endl;
            std::ifstream file(filename);
            std::string key {};
            T value {};
            while ((file >> key >> value) && m_entries < max_entries) {
                std::replace(key.begin(), key.end(), '_', ' '); // replace underscores with spaces
                encryptDecrypt(value);
                SetValue(key, value);
            }
            file.close();
        }

        // Encrypt and Decrypt Function
        void encryptDecrypt(T& value) {};
    public:
        // Returns or creates an instance of type Database
        static std::shared_ptr<Database> getInstance(const std::string& filename) {
            return (m_database) ? m_database : m_database = std::shared_ptr<Database<T>>(new Database<T>(filename));
        }
        // A query that searches in the array of keys for the first parameter
        Err_Status GetValue(const std::string& key, T& value) {
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
        Err_Status SetValue(const std::string& key, const T& value) {
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
        ~Database() {
            std::cout << "[" << this << "]" << " ~Database()" << std::endl;
            std::ofstream databaseBackup(m_filename + ".bkp.txt");
            for (size_t i = { 0 }; i < m_entries; i++) {
                encryptDecrypt(m_values[i]);
                databaseBackup << std::left << std::setw(25) << m_keys[i] << " -> " << m_values[i] << std::endl;
            }
        }
    };

    // Specialized Encryption/Decryption functions
    template<>
    void Database<std::string>::encryptDecrypt(std::string& value) {
        const char secret[]{ "secret encryption key" };
        for (char& c : value) {
            for (const char& k : secret) {
                c = c ^ k;
            }
        }
    }

    template<>
    void Database<long long>::encryptDecrypt(long long& value) {
        const char secret[]{ "super secret encryption key" };
        char* bytes = reinterpret_cast<char*>(&value);
        size_t numBytes = sizeof(value);
        for (size_t i = 0; i < numBytes; i++) {
            for (const char& k : secret) {
                bytes[i] = bytes[i] ^ k;
            }
        }
    }
}

#endif // SDDS_DATABASE_H