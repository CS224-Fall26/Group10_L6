
#ifndef DISPATCH_CENTER_HPP
#define DISPATCH_CENTER_HPP

#include <string>
using namespace std;

// Forward declaration of our two parent classes
// We will use their pointers in DispatchCenter
class Emergency;
class RescueUnit;


// This class will manage all emergencies and rescue units
class DispatchCenter {

private:

    // Array to store pointers of emergencies
    Emergency* incidents[30];

    // Array to store pointers of rescue units
    RescueUnit* units[15];

    // To count how many emergencies and units we have
    int incidentCount;
    int unitCount;


public:

    // Constructor
    DispatchCenter();

    // Destructor to delete the objects stored in arrays
    ~DispatchCenter();

    // We dont want to copy our DispatchCenter
    // Because it owns dynamically created objects
    DispatchCenter(const DispatchCenter&) = delete;
    DispatchCenter& operator=(const DispatchCenter&) = delete;


    // Function to report a fire emergency
    bool reportFire(int id, const string& location,
                    int severity, int peopleTrapped);

    // Function to report a flood emergency
    bool reportFlood(int id, const string& location,
                     int severity, int waterLevelCm);


    // Function to register a new rescue unit
    bool registerUnit(RescueUnit* unit);


    // These functions are used to search emergencies
    // One searches using ID and other using location
    Emergency* findIncident(int id) const;
    Emergency* findIncident(const string& location) const;


    // Function for manually assigning a rescue unit
    bool dispatch(int incidentId, int unitId);


    // Functions to display our records
    void viewEmergencies() const;
    void viewUnits() const;

};

#endif
