// Name: Aryan Khurana
// Seneca Student ID: 145282216
// Seneca email: akhurana22@myseneca.ca
// Date of completion: 08 March 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Station.h"
#include <iostream>
#include <iomanip>
#include "Utilities.h"

namespace sdds {
    // This constructor extracts name, starting serial number, and quantity from the string
    Station::Station(const std::string str) {
        Utilities utils {};
        size_t next_pos { 0 };
        bool more = true;

        // Extracting the name
        m_item = utils.extractToken(str, next_pos, more);
        // Extracting the Serial Number
        m_next = std::stoi(utils.extractToken(str, next_pos, more));
        // Extracting the quantity in stock
        m_quantity = std::stoi(utils.extractToken(str, next_pos, more));
        // Extracting the description
        m_widthField = std::max(m_widthField, utils.getFieldWidth());
        m_description = utils.extractToken(str, next_pos, more);
        m_id = ++id_generator;
    }

    // Returns the name of the current Station object
    const std::string& Station::getItemName() const { return m_item; }

    // Returns the next serial number to be used on the assembly line and increments m_serialNumber
    size_t Station::getNextSerialNumber() { return m_next; }

    // Returns the remaining quantity of items in the Station object
    size_t Station::getQuantity() const { return m_quantity; }

    // Subtracts 1 from the available quantity; should not drop below 0
    void Station::updateQuantity() {
        (m_quantity > 0) ? m_quantity -= 1 : m_quantity;
    }

    // Inserts information about the current object into stream os
    void Station::display(std::ostream& os, bool full) const {
        os << std::setfill('0') << std::right << std::setw(3) << m_id << " | ";
        os << std::setw(m_widthField) << std::left << std::setfill(' ') << m_item << " | ";
        os << std::setw(6) << std::right << std::setfill('0') << m_next << " | ";
        if (full) {
            os << std::setfill(' ') << std::setw(4) << std::right << m_quantity << " |";
            os << std::left <<  m_description;
        }
        os << std::endl;
    }
}