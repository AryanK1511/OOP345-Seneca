/*
*****************************************************************************
                              Bakery.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 16 March 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Bakery.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using std::endl;

namespace sdds {
    // Constructor that populates the collection
    Bakery::Bakery(const char* filename) {
        // Opening the file and checking if it has opened successfully
        std::ifstream file(filename);
        if (!file) {
            throw "Error: Could not open file";
        }

        // Reading and storing data in collection
        std::string data {};
        while (std::getline(file, data)) {
            BakedGood bakedGood {};
            // Using the transform algorithm to convert baked type string to uppercase to avoid errors while validating
            std::string bakedType = data.substr(0, 8);
            transform(bakedType.begin(), bakedType.end(), bakedType.begin(), ::toupper);

            // Assigning data
            bakedGood.m_bakedType = strip(bakedType) == "BREAD" ? BakedType::BREAD : BakedType::PASTERY;
            bakedGood.m_description = strip(data.substr(8, 20));
            bakedGood.m_shelfLife = std::stoi(strip(data.substr(28, 14)));
            bakedGood.m_stockAmount = std::stoi(strip(data.substr(42, 8)));
            bakedGood.m_price = std::stod(strip(data.substr(50, 6)));
            // Adding the baked good to our collection
            m_collection.push_back(bakedGood);
        }
        // Closing the file
        file.close();
    }

    // Print the content of the collection into the parameter
    void Bakery::showGoods(std::ostream& os) const {
        for_each(m_collection.begin(), m_collection.end(), [&os](auto bakedGood) { os << bakedGood; });
    }

    // Inserts one BakedGood into the first parameter
    std::ostream& operator<<(std::ostream& out, const BakedGood& b) {
        out << "* " << std::left << std::setw(10) << (b.m_bakedType == BakedType::BREAD ? "Bread" : "Pastry");
        out << " * " << std::left << std::setw(20) << b.m_description;
        out << " * " << std::left << std::setw(5) << b.m_shelfLife;
        out << " * " << std::left << std::setw(5) << b.m_stockAmount;
        out << " * " << std::right << std::fixed << std::setprecision(2) << std::setw(8) << b.m_price;
        out << " *" << endl;
        return out;
    }

    // Strips all the white spaces from a string
    std::string strip(const std::string& str) {
        std::string returnVal {};
        size_t first = str.find_first_not_of(' ');
        size_t last = str.find_last_not_of(' ');
        (std::string::npos == first) ? returnVal = str : returnVal = str.substr(first, (last - first + 1));
        return returnVal;
    }
}