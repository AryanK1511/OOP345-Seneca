// Name: Aryan Khurana
// Seneca Student ID: 145282216
// Seneca email: akhurana22@myseneca.ca
// Date of completion: 06 April 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <iostream>

namespace sdds {
    class Utilities {
    private:
        size_t m_widthField { 1 };
        inline static char m_delimiter {};
    public:
        Utilities() = default;
        // Sets the field width of the current object to the value of parameter
        void setFieldWidth(size_t newWidth);
        // Returns the field width of the current object
        size_t getFieldWidth() const;
        // Extracts a token from string str referred to by the first parameter.
        std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
        // Strips white space characters from a string
        std::string strip(const std::string& str);
        // Sets the delimiter for this class to the character received
        static void setDelimiter(char newDelimiter);
        // Returns the delimiter for this class.
        static char getDelimiter();
    };
}

#endif // SDDS_UTILITIES_H