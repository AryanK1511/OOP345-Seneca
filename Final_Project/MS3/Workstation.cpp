// Name: Aryan Khurana
// Seneca Student ID: 145282216
// Seneca email: akhurana22@myseneca.ca
// Date of completion: 25 March 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Workstation.h"
#include <iostream>

namespace sdds {
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
        bool orderMoved { false };
        // Check if the item has been filled in the order and the orders deque is not empty
        if ((!(m_orders.empty())) && (m_orders.front().isItemFilled(getItemName()))) {
            // Check whether there is a next station to move the order to
            if (m_pNextStation) {
                // Move the order to the next station
                *m_pNextStation += std::move(m_orders.front());
                m_orders.pop_front();
                orderMoved = true;
            }
            // If there is no stations left, check whether the order has been completed or not
            else {
                // If order is completed, move the order to the completed orders deque
                if (m_orders.front().isOrderFilled()) {
                    g_completed.push_back(std::move(m_orders.front()));
                }
                // If the order is not completed, move the order to the incomplete orders deque
                else {
                    g_incomplete.push_back((std::move(m_orders.front())));
                }
                m_orders.pop_front();
                orderMoved = true;
            }
        }

        return orderMoved;
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