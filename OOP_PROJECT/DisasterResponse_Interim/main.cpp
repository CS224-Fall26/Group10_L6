#include <iostream>
#include <string>

#include "DispatchCenter.hpp"
#include "Emergency.hpp"
#include "RescueUnit.hpp"
#include "FireTruck.hpp"
#include "RescueBoat.hpp"

using namespace std;

// Takes valid integer input from user
int readInt(const string& message)
{
    int number;

    while (true)
    {
        cout << message;

        if (cin >> number)
        {
            cin.ignore(10000, '\n');
            return number;
        }

        cout << "Please enter a valid number." << endl;

        cin.clear();
        cin.ignore(10000, '\n');
    }
}

// Takes text input including spaces
string readText(const string& message)
{
    string value;

    cout << message;
    getline(cin, value);

    return value;
}

int main()
{
    // Object to manage emergencies and rescue units
    DispatchCenter center;

    int choice;

    // Menu keeps running until user enters 0
    do
    {
        cout << "\n===== CITY DISASTER RESPONSE SYSTEM =====" << endl;

        cout << "1. Report Emergency" << endl;
        cout << "2. Register Rescue Unit" << endl;
        cout << "3. View Records" << endl;
        cout << "4. Dispatch Rescue Unit" << endl;
        cout << "5. Search Emergency" << endl;
        cout << "0. Exit" << endl;

        choice = readInt("Enter your choice: ");

        // Option 1: Report emergency
        if (choice == 1)
        {
            cout << "\n1. Fire" << endl;
            cout << "2. Flood" << endl;

            int type = readInt("Enter emergency type: ");

            // Checking emergency type
            if (type != 1 && type != 2)
            {
                cout << "Invalid emergency type." << endl;
                continue;
            }

            int id = readInt("Enter Emergency ID: ");

            string location = readText("Enter Location: ");

            int severity = readInt("Enter Severity (1-5): ");

            bool added = false;

            // Reporting fire emergency
            if (type == 1)
            {
                int trapped = readInt("Number of people trapped: ");

                added = center.reportFire(id, location,
                                          severity, trapped);
            }

            // Reporting flood emergency
            else
            {
                int water = readInt("Water level in cm: ");

                added = center.reportFlood(id, location,
                                           severity, water);
            }

            // Checking if emergency was added
            if (added)
            {
                cout << "Emergency reported successfully." << endl;
            }
            else
            {
                cout << "Could not report emergency." << endl;
                cout << "Check ID, values or storage limit." << endl;
            }
        }

        // Option 2: Register rescue unit
        else if (choice == 2)
        {
            cout << "\n1. Fire Truck" << endl;
            cout << "2. Rescue Boat" << endl;

            int type = readInt("Enter rescue unit type: ");

            // Checking rescue unit type
            if (type != 1 && type != 2)
            {
                cout << "Invalid rescue unit type." << endl;
                continue;
            }

            int id = readInt("Enter Unit ID: ");

            string name = readText("Enter Unit Name: ");

            // Parent class pointer
            RescueUnit* unit = nullptr;

            // Creating fire truck object
            if (type == 1)
            {
                unit = new FireTruck(id, name);
            }

            // Creating rescue boat object
            else
            {
                unit = new RescueBoat(id, name);
            }

            // Registering unit in dispatch center
            if (center.registerUnit(unit))
            {
                cout << "Rescue unit registered successfully." << endl;
            }
            else
            {
                // Free memory if registration fails
                delete unit;

                cout << "Could not register rescue unit." << endl;
                cout << "Check ID, name or storage limit." << endl;
            }
        }

        // Option 3: View all records
        else if (choice == 3)
        {
            cout << "\n----- EMERGENCIES -----" << endl;

            // Display all emergencies
            center.viewEmergencies();

            cout << "\n----- RESCUE UNITS -----" << endl;

            // Display all rescue units
            center.viewUnits();
        }

        // Option 4: Manually dispatch a rescue unit
        else if (choice == 4)
        {
            int incidentId = readInt("Enter Emergency ID: ");

            int unitId = readInt("Enter Rescue Unit ID: ");

            // Checks ID, availability and compatibility
            bool dispatched = center.dispatch(incidentId, unitId);

            if (dispatched)
            {
                cout << "Rescue unit dispatched successfully." << endl;
            }
            else
            {
                cout << "Dispatch failed." << endl;
                cout << "Check IDs, availability or unit type." << endl;
            }
        }

        // Option 5: Search emergency
        else if (choice == 5)
        {
            cout << "\n1. Search by ID" << endl;
            cout << "2. Search by Location" << endl;

            int searchType = readInt("Enter search type: ");

            // Pointer to store found emergency
            Emergency* result = nullptr;

            // Searching by ID
            if (searchType == 1)
            {
                int id = readInt("Enter Emergency ID: ");

                result = center.findIncident(id);
            }

            // Searching by location
            else if (searchType == 2)
            {
                string location = readText("Enter Location: ");

                result = center.findIncident(location);
            }
            else
            {
                cout << "Invalid search choice." << endl;
                continue;
            }

            // Checking if emergency exists
            if (result == nullptr)
            {
                cout << "Emergency not found." << endl;
            }
            else
            {
                // Calls display of respective child class
                result->display();
            }
        }

        // Invalid menu choice
        else if (choice != 0)
        {
            cout << "Invalid menu choice." << endl;
        }

    } while (choice != 0);

    cout << "Program closed." << endl;

    return 0;
}