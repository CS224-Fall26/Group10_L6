
#include "FireEmergency.hpp"
#include <iostream>

using namespace std;


// This is the constructor of our FireEmergency class
// First we are calling the parent class constructor
// Then we are setting peopleTrapped which is our own variable

FireEmergency::FireEmergency(int id, const string& location, int severity, int peopleTrapped) : Emergency(id, location, severity)
{
    this->peopleTrapped = peopleTrapped;
}


// This function returns the type of emergency
// We have overridden it from the Emergency parent class

string FireEmergency::getType() const
{
    return "Fire";
}


// This function displays the details of a fire emergency
// We use getters because variables in Emergency are private

void FireEmergency::display() const
{
    cout << "[Fire] ID: " << getId() << endl;
    cout << "Location: " << getLocation() << endl;
    cout << "Severity: " << getSeverity() << endl;
    cout << "People Trapped: " << peopleTrapped << endl;


    // Now checking the current status of this emergency

    if (getStatus() == "PENDING")
    {
        cout << "Status: Pending" << endl;
    }

    else if (getStatus() == "ASSIGNED")
    {
        cout << "Status: Assigned" << endl;
        // Showing which rescue unit has been assigned
        cout << "Assigned Unit ID: " << getAssignedUnitId() << endl;
    }

    else if (getStatus() == "RESOLVED")
    {
        cout << "Status: Resolved" << endl;
    }
}
