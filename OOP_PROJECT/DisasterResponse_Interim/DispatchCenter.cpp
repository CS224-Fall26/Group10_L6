
#include "DispatchCenter.hpp"
#include "Emergency.hpp"
#include "FireEmergency.hpp"
#include "FloodEmergency.hpp"
#include "RescueUnit.hpp"
#include <iostream>

using namespace std;


// Constructor of our DispatchCenter
// We are initially setting both counts to zero

DispatchCenter::DispatchCenter()
{
    incidentCount = 0;
    unitCount = 0;

    // Initially there are no emergency objects
    for (int i = 0; i < 30; i++)
    {
        incidents[i] = nullptr;
    }

    // Same thing for our rescue units
    for (int i = 0; i < 15; i++)
    {
        units[i] = nullptr;
    }
}


// Destructor to delete all the objects we created

DispatchCenter::~DispatchCenter()
{
    for (int i = 0; i < incidentCount; i++)
    {
        delete incidents[i];
    }

    for (int i = 0; i < unitCount; i++)
    {
        delete units[i];
    }
}


// This function reports a new Fire emergency

bool DispatchCenter::reportFire(int id, const string& location,
                                int severity, int peopleTrapped)
{
    // Checking if our emergency array is full
    if (incidentCount >= 30)
    {
        return false;
    }

    // Checking if the entered information is valid
    if (id <= 0 || location.empty() || severity < 1 ||
        severity > 5 || peopleTrapped < 0)
    {
        return false;
    }

    // Checking if this ID already exists
    if (findIncident(id) != nullptr)
    {
        return false;
    }

    // Creating a new FireEmergency object
    incidents[incidentCount] = new FireEmergency(id, location,
                                                severity, peopleTrapped);

    incidentCount++;

    return true;
}


// This function reports a new Flood emergency

bool DispatchCenter::reportFlood(int id, const string& location,
                                 int severity, int waterLevelCm)
{
    if (incidentCount >= 30)
    {
        return false;
    }

    // Checking the entered values
    if (id <= 0 || location.empty() || severity < 1 ||
        severity > 5 || waterLevelCm < 0)
    {
        return false;
    }

    // We cannot have two emergencies with the same ID
    if (findIncident(id) != nullptr)
    {
        return false;
    }

    // Creating a FloodEmergency object
    incidents[incidentCount] = new FloodEmergency(id, location,
                                                  severity, waterLevelCm);

    incidentCount++;

    return true;
}


// This function registers a rescue unit

bool DispatchCenter::registerUnit(RescueUnit* unit)
{
    // Checking if the pointer is empty or array is full
    if (unit == nullptr || unitCount >= 15)
    {
        return false;
    }

    // Checking the unit ID and name
    if (unit->getId() <= 0 || unit->getName().empty())
    {
        return false;
    }

    // Checking if the unit ID is already being used
    for (int i = 0; i < unitCount; i++)
    {
        if (units[i]->getId() == unit->getId())
        {
            return false;
        }
    }

    // Storing the new rescue unit pointer in our array
    units[unitCount] = unit;

    unitCount++;

    return true;
}


// This function searches for an emergency using its ID

Emergency* DispatchCenter::findIncident(int id) const
{
    for (int i = 0; i < incidentCount; i++)
    {
        if (incidents[i]->getId() == id)
        {
            return incidents[i];
        }
    }

    // If we did not find any matching emergency
    return nullptr;
}


// This function searches for an emergency using location
// Both findIncident functions show function overloading

Emergency* DispatchCenter::findIncident(const string& location) const
{
    for (int i = 0; i < incidentCount; i++)
    {
        if (incidents[i]->getLocation() == location)
        {
            return incidents[i];
        }
    }

    return nullptr;
}


// This function manually dispatches a rescue unit
// We need both emergency ID and rescue unit ID

bool DispatchCenter::dispatch(int incidentId, int unitId)
{
    // First finding the emergency
    Emergency* incident = findIncident(incidentId);

    // If emergency does not exist we cannot dispatch
    if (incident == nullptr)
    {
        return false;
    }

    // We can only dispatch to a pending emergency
    if (incident->getStatus() != "PENDING")
    {
        return false;
    }

    // Now searching for the rescue unit
    for (int i = 0; i < unitCount; i++)
    {
        if (units[i]->getId() == unitId)
        {
            // Checking if the unit is already busy
            if (!units[i]->isAvailable())
            {
                return false;
            }

            // Checking if our unit can handle this emergency
            // FireTruck handles Fire, RescueBoat handles Flood
            if (!units[i]->canHandle(*incident))
            {
                return false;
            }

            // Storing the rescue unit ID in emergency
            incident->setAssignedUnitId(unitId);

            // Updating emergency status
            incident->setStatus("ASSIGNED");

            // Making the rescue unit busy
            units[i]->setAvailability(false);

            // Storing the emergency ID in rescue unit
            units[i]->setAssignedEmergencyId(incidentId);

            return true;
        }
    }

    // If unit ID was not found
    return false;
}


// This function displays all reported emergencies

void DispatchCenter::viewEmergencies() const
{
    if (incidentCount == 0)
    {
        cout << "No emergencies reported." << endl;
        return;
    }

    for (int i = 0; i < incidentCount; i++)
    {
        incidents[i]->display();
    }
}


// This function displays all registered rescue units

void DispatchCenter::viewUnits() const
{
    if (unitCount == 0)
    {
        cout << "No rescue units registered." << endl;
        return;
    }

    for (int i = 0; i < unitCount; i++)
    {
        units[i]->display();
    }
}
