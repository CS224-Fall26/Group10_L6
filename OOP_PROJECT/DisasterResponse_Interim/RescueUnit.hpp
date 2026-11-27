
#ifndef RESCUE_UNIT_HPP
#define RESCUE_UNIT_HPP

#include <string>
using namespace std;

// We are declaring Emergency here because
// we will use it in the canHandle function
class Emergency;


// This is our parent class for all rescue units
class RescueUnit {

private:
    int id;             // Unique ID of rescue unit
    string name;        // Name of the rescue vehicle
    bool available;     // True if unit is free, false if busy

    int assignedEmergencyId; // ID of emergency assigned
                             // -1 means no emergency assigned

public:

    // Constructor to set the rescue unit details
    RescueUnit(int id, const string& name);

    // Virtual destructor because we have child classes
    virtual ~RescueUnit();


    // Getter functions
    int getId() const;

    const string& getName() const;

    bool isAvailable() const;

    int getAssignedEmergencyId() const;


    // Setter functions
    void setAvailability(bool value);

    void setAssignedEmergencyId(int emergencyId);


    // Returns the type of rescue unit
    // Child classes will implement this function
    virtual string getType() const = 0;


    // Checks if the rescue unit can handle an emergency
    // FireTruck handles Fire and RescueBoat handles Flood
    virtual bool canHandle(const Emergency& emergency) const = 0;


    // Displays details of the rescue unit
    virtual void display() const = 0;

};

#endif
