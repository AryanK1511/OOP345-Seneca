// Name: Aryan Khurana
// Seneca Student ID: 145282216
// Seneca email: akhurana22@myseneca.ca
// Date of completion: 06 April 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H

#include "Station.h"
#include <iostream>

namespace sdds {
    // Item Definition
    struct Item {
        std::string m_itemName;
        size_t m_serialNumber{0};
        bool m_isFilled{false};
        Item(const std::string& src) : m_itemName(src) {};
    };

    class CustomerOrder {
    private:
        std::string m_name {};
        std::string m_product {};
        size_t m_cntItem { 0 };
        Item** m_lstItem { nullptr };
        static size_t m_widthField;
    public:
        // Default Constructor
        CustomerOrder() = default;
        // Overloaded Constructor - Extract the tokens from the string and populate the current instance
        CustomerOrder(const std::string& str);
        // Copy Operations
        CustomerOrder(const CustomerOrder&);
        CustomerOrder& operator=(const CustomerOrder&) = delete;
        // Move Semantics
        CustomerOrder(CustomerOrder&& co) noexcept;
        CustomerOrder& operator=(CustomerOrder&& co) noexcept;
        // Destructor
        virtual ~CustomerOrder();
        // Returns true if all the items in the order have been filled
        bool isOrderFilled() const;
        // Returns true if all items specified by itemName have been filled
        bool isItemFilled(const std::string& itemName) const;
        // This modifier fills one item in the current order that the Station specified in the first parameter handles
        void fillItem(Station& station, std::ostream& os);
        // Displays the state of the current object
        void display(std::ostream& os = std::cout) const;
    };
}

#endif // SDDS_CUSTOMERORDER_H