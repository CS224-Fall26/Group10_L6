#ifndef FIRE_EMERGENCY_HPP
#define FIRE_EMERGENCY_HPP

#include "Emergency.hpp"

using namespace std;

// This is our child class which inherits from Emergency
class FireEmergency : public Emergency {

private:

    // This variable is only needed for fire emergencies
    int peopleTrapped;

public:

    // Constructor to set the fire emergency details
    FireEmergency(int id, const string& location,
                  int severity, int peopleTrapped);

    // This function tells us the type of emergency
    // We are overriding the function from parent class
    string getType() const override;

    // This will display all the fire emergency details
    // Every child class has its own display function
    void display() const override;

};

#endif
