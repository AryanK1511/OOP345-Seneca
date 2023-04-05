// Name: Aryan Khurana
// Seneca Student ID: 145282216
// Seneca email: akhurana22@myseneca.ca
// Date of completion: 05 April 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <iostream>

namespace sdds {
    class Station {
    private:
        size_t m_id {};
        std::string m_item {};
        std::string m_description {};
        size_t m_serial {};
        size_t m_quantity { 0 };
        inline static size_t m_widthField { 0 };
        inline static size_t id_generator { 0 };
    public:
        Station() = default;
        // This constructor extracts name, starting serial number, and quantity from the string
        Station(const std::string str);
        // Returns the name of the current Station object
        const std::string& getItemName() const;
        // Returns the next serial number to be used on the assembly line and increments m_serialNumber
        size_t getNextSerialNumber();
        // Returns the remaining quantity of items in the Station object
        size_t getQuantity() const;
        // Subtracts 1 from the available quantity; should not drop below 0
        void updateQuantity();
        // Inserts information about the current object into stream os
        void display(std::ostream& os, bool full) const;
    };
}

#endif // SDDS_STATION_H