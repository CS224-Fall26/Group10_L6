
#include "Emergency.hpp"

using namespace std;


// This is the constructor of our Emergency class
Emergency::Emergency(int id, const string& location, int severity) //yaha pe const islie likh rhe h kein ,woh change ksrsktha h aur hm by reference pass krhe
{
    this->id = id;
    this->location = location;
    this->severity = severity;

    status = "PENDING";  // Initially no rescue unit is assigned
    assignedUnitId = -1;  // -1 means no unit is assigned yet
}


// Destructor of our Emergency class
// It is virtual in the header because we also have child classes
Emergency::~Emergency()
{
}


// These functions are used to get the private data

int Emergency::getId() const
{
    return id;
}

const string& Emergency::getLocation() const
{
    return location;
}

int Emergency::getSeverity() const
{
    return severity;
}

string Emergency::getStatus() const
{
    return status;
}

int Emergency::getAssignedUnitId() const
{
    return assignedUnitId;
}


// These functions are used to update some information

void Emergency::setStatus(string newStatus)
{
    status = newStatus;
}

void Emergency::setAssignedUnitId(int unitId)
{
    assignedUnitId = unitId;
}
