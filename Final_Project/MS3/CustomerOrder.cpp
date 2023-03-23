// Name: Aryan Khurana
// Seneca Student ID: 145282216
// Seneca email: akhurana22@myseneca.ca
// Date of completion: 25 March 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "CustomerOrder.h"
#include "Utilities.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
using std::endl;

namespace sdds {
    size_t CustomerOrder::m_widthField = 0;

    // Overloaded Constructor - Extract the tokens from the string and populate the current instance
    CustomerOrder::CustomerOrder(const std::string& str) {
        size_t next_pos = 0;
        bool more = true;
        Utilities util {};
        size_t startCpy {};
        m_name = util.extractToken(str, next_pos, more);
        m_product = util.extractToken(str, next_pos, more);
        startCpy = next_pos;
        // Counting the number of items
        while (more) {
            util.extractToken(str, next_pos, more);
            m_cntItem++;
        }
        // Reset position
        next_pos = startCpy;
        more = true;

        // Dynamically allocating memory for the array of pointers
        m_lstItem = new Item*[m_cntItem];
        for (size_t i = 0; i < m_cntItem; i++) {
            m_lstItem[i] = new Item(util.extractToken(str, next_pos, more));
        }

        // Setting the width
        (m_widthField < util.getFieldWidth()) ? m_widthField = util.getFieldWidth() : m_widthField;
    }

    // Copy constructor
    CustomerOrder::CustomerOrder(const CustomerOrder& other) { throw "Attempting to copy. Operation not allowed."; }


    // Move Semantics
    CustomerOrder::CustomerOrder(CustomerOrder&& co) noexcept {
        *this = std::move(co);
    }

    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& co) noexcept {
        if (this != &co) {
            for (size_t i = 0; i < m_cntItem; i++) {
                // Deallocating memory for individual items
                delete m_lstItem[i];
            }
            // Deallocating memory for the array of item pointers
            delete[] m_lstItem;
            m_name = co.m_name;
            co.m_name = "";
            m_product = co.m_product;
            co.m_product = "";
            m_cntItem = co.m_cntItem;
            co.m_cntItem = 0;
            m_lstItem = co.m_lstItem;
            co.m_lstItem = nullptr;
        }
        return *this;
    }

    // Destructor
    CustomerOrder::~CustomerOrder() {
        for (size_t i = 0; i < m_cntItem; i++) {
            // Deallocating memory for individual items
            delete m_lstItem[i];
        }
        // Deallocating memory for the array of item pointers
        delete[] m_lstItem;
    }

    // Returns true if all the items in the order have been filled
    bool CustomerOrder::isOrderFilled() const {
        bool flag = true;
        for (size_t i = 0; i < m_cntItem && flag; i++) {
            if (!m_lstItem[i]->m_isFilled) {
                flag = false;
            }
        }
        return flag;
    }

    // Returns true if all items specified by itemName have been filled
    bool CustomerOrder::isItemFilled(const std::string& itemName) const {
        bool flag = true;
        for (size_t i = 0; i < m_cntItem && flag; i++) {
            if (m_lstItem[i]->m_itemName == itemName) {
                if (!m_lstItem[i]->m_isFilled) {
                    flag = false;
                }
            }
        }
        return flag;
    }

    // This modifier fills one item in the current order that the Station specified in the first parameter handles
    void CustomerOrder::fillItem(Station& station, std::ostream& os) {
        bool filled { false };
        for (size_t i = 0; i < m_cntItem && !filled; i++) {
            if ((m_lstItem[i]->m_itemName == station.getItemName()) && (station.getQuantity() > 0)) {
                // Subtracting one from the inventory
                station.updateQuantity();
                m_lstItem[i]->m_serialNumber++;
                m_lstItem[i]->m_isFilled = true;
                filled = true;
                os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
            } else if ((m_lstItem[i]->m_itemName == station.getItemName()) && (station.getQuantity() == 0)) {
                os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
            }
        }
    }

    // Displays the state of the current object
    void CustomerOrder::display(std::ostream& os) const {
        os << m_name << " - " << m_product << endl;
        for (size_t i = 0; i < m_cntItem; i++) {
            os << "[" << std::setfill('0') << std::setw(6) << m_lstItem[i]->m_serialNumber << "] ";
            os << std::left << std::setfill(' ') << std::setw(m_widthField) << m_lstItem[i]->m_itemName << "   - " << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED");
            os << std::endl;
        }
    }
}