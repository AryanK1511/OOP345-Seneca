// Name: Aryan Khurana
// Seneca Student ID: 145282216
// Seneca email: akhurana22@myseneca.ca
// Date of completion: 05 April 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Workstation.h"
#include <iostream>

namespace sdds {
    // ========== GLOBAL VARIABLES ===========
    // Holds the orders to be placed onto the assembly line at the first station.
    std::deque<CustomerOrder> g_pending;
    // Holds the orders that have been removed from the last station and have been completely filled.
    std::deque<CustomerOrder> g_completed;
    // Holds the orders that have been removed from the last station and could not be filled completely.
    std::deque<CustomerOrder> g_incomplete;

    // Receives a reference to an unmodifiable reference to std::string and passes it to the Station base class
    Workstation::Workstation(const std::string& str) : Station(str) {}

    // Modifier fills the order at the front of the queue if there are CustomerOrders in the queue
    void Workstation::fill(std::ostream& os) {
        if (!m_orders.empty()) {
            m_orders.front().fillItem(*this, os);
        }
    }

    // Attempts to move the order at the front of the queue to the next station
    bool Workstation::attemptToMoveOrder() {
        bool moved{};
        // Checking if the orders exist
        if (!m_orders.empty()) {
            // Checking if the order is filled
            if (getQuantity() == 0 || m_orders.front().isItemFilled(getItemName())) {
                if (!m_pNextStation) {
                    if (m_orders.front().isOrderFilled()) {
                        g_completed.push_back(std::move(m_orders.front()));
                    } else {
                        g_incomplete.push_back(std::move(m_orders.front()));
                    }
                }
                // Move to next station
                else {
                    *m_pNextStation += std::move(m_orders.front());
                }
                m_orders.pop_front();
                moved = true;
            }
        }
        return moved;
    }

    // Stores the address of the referenced Workstation object in the pointer to the m_pNextStation
    void Workstation::setNextStation(Workstation* station) { m_pNextStation = station; }

    // This query returns the address of next Workstation
    Workstation* Workstation::getNextStation() const { return m_pNextStation; }

    // This query inserts the name of the Item for which the current object is responsible into stream os
    void Workstation::display(std::ostream& os) const {
        os << (this)->getItemName() << " --> ";
        (m_pNextStation) ?
        (os << m_pNextStation->getItemName()) :
        (os << "End of Line");
        os << "\n";
    }

    // Moves the CustomerOrder referenced in parameter newOrder to the back of the queue.
    Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
        m_orders.push_back(std::move(newOrder));
        return *this;
    }
}