// Name: Aryan Khurana
// Seneca Student ID: 145282216
// Seneca email: akhurana22@myseneca.ca
// Date of completion: 30 March 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "LineManager.h"
#include "Utilities.h"
#include <iostream>
#include <fstream>
#include <algorithm>

namespace sdds {
    // It loads the contents of the file, stores the address of the next workstation in each element of the collection, identifies the first station in the assembly line and stores its address in the m_firstStation attribute
    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) :
    m_activeLine(stations) {
        std::ifstream infile(file);
        // Checking whether the file was opened successfully
        if (!infile) {
            throw "ERROR: Unable to open file";
        }
        // Reading from the file
        Utilities utils {};
        std::string str {};
        size_t next_pos { 0 };
        size_t next_copy = next_pos;
        bool more { true };
        while (std::getline(infile, str)) {
            // Resetting the index
            next_pos = next_copy;
            // Storing the names of the current and the next stations
            std::string tempCurrStation {}, tempNextStation {};
            tempCurrStation = utils.extractToken(str, next_pos, more);
            // This is to prevent the program from extracting twice if there is no delimiter and checking if there is a next station that exists
            if (!(next_pos == next_copy)) {
                tempNextStation = utils.extractToken(str, next_pos, more);
            }
            // Finding the current station in the collection
            auto currStation = std::find_if(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* station){
                return station->getItemName() == tempCurrStation;
            });

            // Finding the next station in the collection
            auto nextStation = std::find_if(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* station){
                return station->getItemName() == tempNextStation;
            });

            // Setting the next station
            (*currStation)->setNextStation(*nextStation);
        }

        // Setting the first station
        auto firstStation = std::find_if(m_activeLine.begin(), m_activeLine.end(), [](Workstation* station){
           return station->getNextStation() == nullptr;
        });
        m_firstStation = *firstStation;
        // Setting the count of customer orders that are still pending
        m_cntCustomer = g_pending.size();
        std::cout << std::endl;
    }

    // Reorders the workstations present in the instance variable
    void LineManager::reorderStations() {

    }

    // Performs one iteration of operations on all the workstations in the current assembly line
    bool LineManager::run(std::ostream& os) {
        static size_t count { 0u };
        os << "Line Manager Iteration: " << count << std::endl;
        // Move the order at the front of the g_pending queue
        if (!g_pending.empty()) {
            *m_firstStation += std::move(g_pending.front());
            g_pending.pop_front();
        }
        // For each station, execute one fill operation
        std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](auto station){
            station->fill(os);
        });
        // For each station, attempt to move an order down the line
        bool allOrdersFilled { true };
//        std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](auto station){
//            allOrdersFilled = station->attemptToMoveOrder();
//        });

        return allOrdersFilled;
    }

    // Displays all active stations on the assembly line in their current order
    void LineManager::display(std::ostream& os) const {
        std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](auto station){
            station->display(os);
        });
    }
}