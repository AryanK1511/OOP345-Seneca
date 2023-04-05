// Name: Aryan Khurana
// Seneca Student ID: 145282216
// Seneca email: akhurana22@myseneca.ca
// Date of completion: 05 April 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include "CustomerOrder.h"
#include "Station.h"
#include <iostream>
#include <deque>

namespace sdds {
    // ========== GLOBAL VARIABLES ===========
    // Holds the orders to be placed onto the assembly line at the first station.
    extern std::deque<CustomerOrder> g_pending;
    // Holds the orders that have been removed from the last station and have been completely filled.
    extern std::deque<CustomerOrder> g_completed;
    // Holds the orders that have been removed from the last station and could not be filled completely.
    extern std::deque<CustomerOrder> g_incomplete;

    class Workstation : public Station {
    private:
        std::deque<CustomerOrder> m_orders {};
        Workstation* m_pNextStation { nullptr };
    public:
        // Default Constructor
        Workstation() = default;
        // Receives a reference to an unmodifiable reference to std::string and passes it to the Station base class
        Workstation(const std::string& str);
        // Disabling copy and move semantics
        Workstation(const Workstation&) = delete;
        Workstation& operator=(const Workstation&) = delete;
        Workstation(Workstation&&) = delete;
        Workstation& operator=(Workstation&&) = delete;
        // Modifier fills the order at the front of the queue if there are CustomerOrders in the queue
        void fill(std::ostream& os = std::cout);
        // Attempts to move the order at the front of the queue to the next station
        bool attemptToMoveOrder();
        // Stores the address of the referenced Workstation object in the pointer to the m_pNextStation
        void setNextStation(Workstation* station = nullptr);
        // This query returns the address of next Workstation
        Workstation* getNextStation() const;
        // This query inserts the name of the Item for which the current object is responsible into stream os
        void display(std::ostream& os = std::cout) const;
        // Moves the CustomerOrder referenced in parameter newOrder to the back of the queue.
        Workstation& operator+=(CustomerOrder&& newOrder);
    };
}

#endif // SDDS_WORKSTATION_H