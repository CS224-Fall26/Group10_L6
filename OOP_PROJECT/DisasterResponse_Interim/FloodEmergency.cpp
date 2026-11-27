
#include "FloodEmergency.hpp"
#include <iostream>

using namespace std;


// This is the constructor of our FloodEmergency class
// First we are calling the parent constructor
// Then setting the water level of our flood

FloodEmergency::FloodEmergency(int id, const string& location,
                               int severity, int waterLevelCm)
    : Emergency(id, location, severity)
{
    this->waterLevelCm = waterLevelCm;
}


// This function returns the type of our emergency
// We are overriding the function from the parent class

string FloodEmergency::getType() const
{
    return "Flood";
}


// This function displays the details of our flood emergency
// We use getters to access the private variables of Emergency

void FloodEmergency::display() const
{
    cout << "[Flood] ID: " << getId() << endl;

    cout << "Location: " << getLocation() << endl;

    cout << "Severity: " << getSeverity() << endl;

    cout << "Water Level: " << waterLevelCm << " cm" << endl;


    // Now checking the status of this flood emergency

    if (getStatus() == "PENDING")
    {
        cout << "Status: Pending" << endl;
    }

    else if (getStatus() == "ASSIGNED")
    {
        cout << "Status: Assigned" << endl;

        // Showing which rescue unit is assigned to this flood
        cout << "Assigned Unit ID: " << getAssignedUnitId() << endl;
    }

    else if (getStatus() == "RESOLVED")
    {
        cout << "Status: Resolved" << endl;
    }
}
