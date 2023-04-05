// Name: Aryan Khurana
// Seneca Student ID: 145282216
// Seneca email: akhurana22@myseneca.ca
// Date of completion: 05 April 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "LineManager.h"
#include "Utilities.h"
#include <iostream>
#include <fstream>
#include <algorithm>

namespace sdds {
    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
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

        // ===== DESIGN TO FIGURE OUT THE FIRST ELEMENT =====
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
            auto currStation = std::find_if(stations.begin(), stations.end(), [&](Workstation* station){
                return station->getItemName() == tempCurrStation;
            });
            // Adding the station to the active line
            m_activeLine.push_back(*currStation);

            // Finding the next station in the collection
            if (tempNextStation.length() > 0) {
                auto nextStation = std::find_if(stations.begin(), stations.end(), [&](Workstation* station){
                    return station->getItemName() == tempNextStation;
                });
                // Setting the next station
                (*currStation)->setNextStation(*nextStation);
            }
        }

        // Setting the first station
//        auto firstStation = std::find_if(stations.begin(), stations.end(), [](Workstation* station){
//            return station->getNextStation() == nullptr;
//        });
        auto firstStation = std::find_if(stations.begin(), stations.end(), [](Workstation* station){
            return station->getItemName() == "Bed";
        });
        m_firstStation = *firstStation;
        // Setting the count of customer orders that are still pending
        m_cntCustomer = g_pending.size();
    }

    // Reorders the workstations present in the instance variable
    void LineManager::reorderStations() {
        std::vector<Workstation*> reorderedStations;
        Workstation* currentStation = m_firstStation;
        while (currentStation != nullptr) {
            reorderedStations.push_back(currentStation);
            currentStation = currentStation->getNextStation();
        }
        m_activeLine = reorderedStations;
    }

    // Performs one iteration of operations on all the workstations in the current assembly line
    bool LineManager::run(std::ostream& os) {
        static size_t iterationCount = 1;
        os << "Line Manager Iteration: " << iterationCount << std::endl;
        ++iterationCount;

        // Put the order from g_pending into first station
        if (!g_pending.empty()) {
            *m_firstStation += std::move(g_pending.front());
            g_pending.pop_front();
        }

        for (auto & i : m_activeLine) {
            i->fill(os);
        }
        for (auto & i : m_activeLine) {
            i->attemptToMoveOrder();
        }

//        for (size_t i = 0; i < m_activeLine.size(); i++)
//            m_activeLine[i]->attemptToMoveOrder();


        // Check if all customer orders have been filled or cannot be filled
        std::cout << g_completed.size() << g_incomplete.size() << m_cntCustomer << std::endl;
        return g_completed.size() + g_incomplete.size() == m_cntCustomer;
//        return true;
    }

    // Displays all active stations on the assembly line in their current order
    void LineManager::display(std::ostream& os) const {
        std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](auto station){
            station->display(os);
        });
    }
}