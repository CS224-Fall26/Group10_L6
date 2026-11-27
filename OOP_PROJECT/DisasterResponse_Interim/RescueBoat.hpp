
#ifndef RESCUE_BOAT_HPP
#define RESCUE_BOAT_HPP

#include "RescueUnit.hpp"

using namespace std;


// This is our child class for rescue boats
// It inherits from our RescueUnit parent class

class RescueBoat : public RescueUnit {

public:

    // Constructor to set the ID and name of the boat
    RescueBoat(int id, const string& name);

    // Returns the type of our rescue unit
    // We are overriding the parent function
    string getType() const override;

    // Checks if our boat can handle the emergency
    // RescueBoat will only handle Flood emergencies
    bool canHandle(const Emergency& emergency) const override;

    // Displays the information about our rescue boat
    void display() const override;

};

#endif
