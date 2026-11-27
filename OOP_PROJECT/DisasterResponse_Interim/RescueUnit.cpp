
#include "RescueUnit.hpp"

using namespace std;


// This is the constructor of our RescueUnit class
// We are setting the details whenever a new rescue unit is created

RescueUnit::RescueUnit(int id, const string& name)
{
    this->id = id;
    this->name = name;

    available = true;  // Initially the rescue unit is free

    assignedEmergencyId = -1;  // No emergency assigned yet
}


// Destructor of our RescueUnit class
// It is virtual in the header because FireTruck and RescueBoat inherit from it

RescueUnit::~RescueUnit()
{
}


// These functions return the private data of our rescue unit

int RescueUnit::getId() const
{
    return id;
}

const string& RescueUnit::getName() const
{
    return name;
}

bool RescueUnit::isAvailable() const
{
    return available;
}

int RescueUnit::getAssignedEmergencyId() const
{
    return assignedEmergencyId;
}


// These functions are used to update the rescue unit information

void RescueUnit::setAvailability(bool value)
{
    available = value;
}

void RescueUnit::setAssignedEmergencyId(int emergencyId)
{
    assignedEmergencyId = emergencyId;
}
