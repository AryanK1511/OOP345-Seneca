// Name: Aryan Khurana
// Seneca Student ID: 145282216
// Seneca email: akhurana22@myseneca.ca
// Date of completion: 06 April 2023
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

        // Designing vectors to determine the first station later in the code
        std::vector<std::string> leftStations;
        std::vector<std::string> rightStations;

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

                // Adding the stations to our vectors
                leftStations.push_back(tempCurrStation);
                rightStations.push_back(tempNextStation);
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

        // Algorithm to determine the first station
        size_t count {};
        std::string fStn {};
        for (const auto & leftStation : leftStations) {
            count = 0;
            for (const auto & rightStation : rightStations) {
                if (leftStation == rightStation) {
                    count++;
                }
            }
            if (count == 0) {
                fStn = leftStation;
                break;
            }
        }

        // Setting the fist station
        auto firstStation = std::find_if(stations.begin(), stations.end(), [&](Workstation* station){
            return station->getItemName() == fStn;
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

        // Apply the fill() member function on each element of m_activeLine
        std::for_each(m_activeLine.begin(), m_activeLine.end(),
          [&](auto& i) {
              i->fill(os);
          });

        // Apply the attemptToMoveOrder() member function on each element of m_activeLine
        std::for_each(m_activeLine.begin(), m_activeLine.end(),
          [&](auto& i) {
              i->attemptToMoveOrder();
          });

        // Check if all customer orders have been filled or cannot be filled
        return g_completed.size() + g_incomplete.size() == m_cntCustomer;
    }

    // Displays all active stations on the assembly line in their current order
    void LineManager::display(std::ostream& os) const {
        std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](auto station){
            station->display(os);
        });
    }
}