
#include "FireTruck.hpp"
#include "Emergency.hpp"
#include <iostream>

using namespace std;


// Constructor of our FireTruck class
// We are calling the RescueUnit parent constructor
// because id and name are already present there

FireTruck::FireTruck(int id, const string& name)
    : RescueUnit(id, name)
{
}


// This function returns the type of our rescue unit

string FireTruck::getType() const
{
    return "Fire Truck";
}


// This function checks if our fire truck can handle an emergency
// Fire trucks can only handle Fire emergencies

bool FireTruck::canHandle(const Emergency& emergency) const
{
    if (emergency.getType() == "Fire")
    {
        return true;
    }
    else
    {
        return false;
    }
}


// This function displays the details of our Fire Truck

void FireTruck::display() const
{
    cout << "[Fire Truck] ID: " << getId() << endl;

    cout << "Name: " << getName() << endl;


    // Checking if our fire truck is free or busy

    if (isAvailable())
    {
        cout << "Status: Available" << endl;
    }
    else
    {
        cout << "Status: Busy" << endl;

        // Showing which emergency our truck is handling
        cout << "Assigned Emergency ID: "
             << getAssignedEmergencyId() << endl;
    }
}
