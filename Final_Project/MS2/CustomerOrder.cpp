// Name: Aryan Khurana
// Seneca Student ID: 145282216
// Seneca email: akhurana22@myseneca.ca
// Date of completion: 23 March 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "CustomerOrder.h"

namespace sdds {
    // Overloaded Constructor - Extract the tokens from the string and populate the current instance
    CustomerOrder::CustomerOrder(const std::string& str) {
        
    }

    // Move Semantics
    CustomerOrder::CustomerOrder(CustomerOrder&& co) noexcept {

    }

    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& co) noexcept {

    }

    // Destructor
    CustomerOrder::~CustomerOrder() {

    }

    // Returns true if all the items in the order have been filled
    bool CustomerOrder::isOrderFilled() const {

    }

    // Returns true if all items specified by itemName have been filled
    bool CustomerOrder::isItemFilled(const std::string& itemName) const {

    }

    // This modifier fills one item in the current order that the Station specified in the first parameter handles
    void CustomerOrder::fillItem(Station& station, std::ostream& os) {

    }

    // Displays the state of the current object
    void CustomerOrder::display(std::ostream& os) const {

    }
}