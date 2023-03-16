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
#include <algorithm>
#include <numeric>
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
        // Printing all the collection content by looping over all the entries
        std::for_each(m_collection.begin(), m_collection.end(), [&os](auto bakedGood) { os << bakedGood << endl; });
        // Calculating total stock amount and price using numeric functions
        auto total_stock = std::accumulate(m_collection.begin(), m_collection.end(), 0, [](int acc, const BakedGood& good) { return acc + good.m_stockAmount; });
        auto total_price = std::accumulate(m_collection.begin(), m_collection.end(), 0.00, [](double acc, const BakedGood& good) { return acc + good.m_price; });
        // Printing the total price and stock amount
        os << "Total Stock: " << total_stock << endl;
        os << "Total Price: " << std::fixed << std::setprecision(2) << total_price << endl;
    }

    // Receives a parameter the name of the field used to sort the collection in ascending order
    void Bakery::sortBakery(std::string field) {
        // Using the transform algorithm to convert field string to uppercase to avoid errors while validating
        std::transform(field.begin(), field.end(), field.begin(), ::toupper);
        // Sorting the collection
        std::sort(m_collection.begin(), m_collection.end(), [field](const BakedGood& bakedGood1, const BakedGood& bakedGood2) {
            bool returnVal {};
            (field == "DESCRIPTION") ? returnVal = bakedGood1. m_description < bakedGood2.m_description : returnVal;
            (field == "SHELF") ? returnVal = bakedGood1. m_shelfLife < bakedGood2.m_shelfLife : returnVal;
            (field == "STOCK") ? returnVal = bakedGood1. m_stockAmount < bakedGood2.m_stockAmount : returnVal;
            (field == "PRICE") ? returnVal = bakedGood1. m_price < bakedGood2.m_price : returnVal;
            return returnVal;
        });
    }

    // Combines the collection of BakedGoods from the current object and the parameter and returns the combined collection
    std::vector<BakedGood> Bakery::combine(Bakery& bakery) {
        std::vector<BakedGood> combined(m_collection.size() + bakery.m_collection.size());
        // Sorting both the vectors
        sortBakery("Price");
        bakery.sortBakery("Price");

        // Merging
        std::merge(m_collection.begin(), m_collection.end(), bakery.m_collection.begin(), bakery.m_collection.end(), combined.begin(), [](const BakedGood& bg1, const BakedGood& bg2) {
            return bg1.m_price < bg2.m_price;
        });
        return combined;
    }

    // Returns true if the collection contains Stock of a BakedGood
    bool Bakery::inStock(const std::string desc, const BakedType& bt) const {
        return std::any_of(m_collection.begin(), m_collection.end(), [desc, bt](const BakedGood& bg) {
            return bg.m_description == desc && bg.m_bakedType == bt;
        });
    }

    // Returns the list of all out of stock items in the collection
    std::list<BakedGood> Bakery::outOfStock(BakedType bt) const {
        std::list<BakedGood> outOfStockItems;
        std::copy_if(m_collection.begin(), m_collection.end(), std::back_inserter(outOfStockItems),[bt](const BakedGood& bg) {
            return bg.m_bakedType == bt && bg.m_stockAmount == 0;
        });
        // Sort the list of out-of-stock items by price
        outOfStockItems.sort([](const BakedGood& bg1, const BakedGood& bg2) {
            return bg1.m_price < bg2.m_price;
        });
        return outOfStockItems;
    }

    // Inserts one BakedGood into the first parameter
    std::ostream& operator<<(std::ostream& out, const BakedGood& b) {
        out << "* " << std::left << std::setw(10) << (b.m_bakedType == BakedType::BREAD ? "Bread" : "Pastry");
        out << " * " << std::left << std::setw(20) << b.m_description;
        out << " * " << std::left << std::setw(5) << b.m_shelfLife;
        out << " * " << std::left << std::setw(5) << b.m_stockAmount;
        out << " * " << std::right << std::fixed << std::setprecision(2) << std::setw(8) << b.m_price;
        out << " * ";
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