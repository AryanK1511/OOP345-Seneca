/*
*****************************************************************************
                              Bakery.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 16 March 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_BAKERY_H
#define SDDS_BAKERY_H

#include <iostream>
#include <vector>
#include <list>

namespace sdds {
    enum class BakedType{
        BREAD, PASTERY
    };

    struct BakedGood {
        BakedType m_bakedType {};
        std::string m_description {};
        int m_shelfLife {};
        int m_stockAmount {};
        double m_price;
    };

    class Bakery {
    private:
        std::vector<BakedGood> m_collection;
    public:
        Bakery() = default;
        // Constructor that populates the collection
        Bakery(const char* filename);
        // Print the content of the collection into the parameter
        void showGoods(std::ostream& os = std::cout) const;
        // Receives a parameter the name of the field used to sort the collection in ascending order
        void sortBakery(std::string field);
        // Combines the collection of BakedGoods from the current object and the parameter and returns the combined collection
        std::vector<BakedGood> combine(Bakery& bakery);
        // Returns true if the collection contains Stock of a BakedGood
        bool inStock(const std::string desc, const BakedType& bt) const;
        // Returns the list of all out of stock items in the collection
        std::list<BakedGood> outOfStock(BakedType bt) const;
    };
    // Inserts one BakedGood into the first parameter
    std::ostream& operator<<(std::ostream& out, const BakedGood& b);
    // Strips all the white spaces from a string
    std::string strip(const std::string& str);
}

#endif // SDDS_BAKERY_H