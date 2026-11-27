
#include "RescueBoat.hpp"
#include "Emergency.hpp"
#include <iostream>

using namespace std;


// Constructor of our RescueBoat class
// We are calling the parent constructor to set ID and name

RescueBoat::RescueBoat(int id, const string& name)
    : RescueUnit(id, name)
{
}


// This function tells us the type of rescue unit

string RescueBoat::getType() const
{
    return "Rescue Boat";
}


// This checks if our boat can handle the emergency
// It will return true only when the emergency is Flood

bool RescueBoat::canHandle(const Emergency& emergency) const
{
    if (emergency.getType() == "Flood")
    {
        return true;
    }
    else
    {
        return false;
    }
}


// This function displays all the details of our rescue boat

void RescueBoat::display() const
{
    cout << "[Rescue Boat] ID: " << getId() << endl;

    cout << "Name: " << getName() << endl;


    // Checking if our boat is available or busy

    if (isAvailable())
    {
        cout << "Status: Available" << endl;
    }
    else
    {
        cout << "Status: Busy" << endl;

        // Displaying which emergency is assigned to the boat
        cout << "Assigned Emergency ID: "
             << getAssignedEmergencyId() << endl;
    }
}
