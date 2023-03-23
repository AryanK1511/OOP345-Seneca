// Name: Aryan Khurana
// Seneca Student ID: 145282216
// Seneca email: akhurana22@myseneca.ca
// Date of completion: 25 March 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Workstation.h"

namespace sdds {
    // Receives a reference to an unmodifiable reference to std::string and passes it to the Station base class
    Workstation::Workstation(const std::string& str) {

    }

    // Modifier fills the order at the front of the queue if there are CustomerOrders in the queue
    void Workstation::fill(std::ostream& os) {

    }

    // Attempts to move the order at the front of the queue to the next station
    bool Workstation::attemptToMoveOrder() {

    }

    // Stores the address of the referenced Workstation object in the pointer to the m_pNextStation
    void Workstation::setNextStation(Workstation* station) {

    }

    // This query returns the address of next Workstation
    Workstation* Workstation::getNextStation() const {

    }

    // This query inserts the name of the Item for which the current object is responsible into stream os
    void Workstation::display(std::ostream& os) const {

    }

    // Moves the CustomerOrder referenced in parameter newOrder to the back of the queue.
    Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {

    }
}