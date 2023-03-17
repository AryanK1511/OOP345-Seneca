// Name: Aryan Khurana
// Seneca Student ID: 145282216
// Seneca email: akhurana22@myseneca.ca
// Date of completion: 17 March 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"
#include <iostream>

namespace sdds {
    // Sets the field width of the current object to the value of parameter
    void Utilities::setFieldWidth(size_t newWidth) { m_widthField = newWidth; }

    // Returns the field width of the current object
    size_t Utilities::getFieldWidth() const { return m_widthField; }

    // Extracts a token from string str referred to by the first parameter.
    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
        std::string extractedToken {};
        size_t endPos = str.find(m_delimiter, next_pos);
        if (endPos != std::string::npos) {
            extractedToken = str.substr(next_pos, endPos - next_pos);
            next_pos = endPos + 1;
            more = true;
        }
        else {
            extractedToken = str.substr(next_pos);
            more = false;
        }
        // Strip all white spaces from the token
        extractedToken = strip(extractedToken);
        // Updating field width
        (extractedToken.length() > m_widthField) ? m_widthField = extractedToken.length() : m_widthField;
        // Throw an error if no token was extracted
        if (extractedToken.empty()) {
            more = false;
            throw "ERROR: Token is empty!";
        }
        return extractedToken;
    }

    // Strips all the white spaces from a string
    std::string Utilities::strip(const std::string& str) {
        std::string returnVal {};
        size_t first = str.find_first_not_of(' ');
        size_t last = str.find_last_not_of(' ');
        (std::string::npos == first) ? returnVal = str : returnVal = str.substr(first, (last - first + 1));
        return returnVal;
    }

    // Sets the delimiter for this class to the character received
    void Utilities::setDelimiter(char newDelimiter) { m_delimiter = newDelimiter; }

    // Returns the delimiter for this class.
    char Utilities::getDelimiter() { return m_delimiter; }
}