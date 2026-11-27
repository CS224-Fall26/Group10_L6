
#ifndef FLOOD_EMERGENCY_HPP
#define FLOOD_EMERGENCY_HPP

#include "Emergency.hpp"

using namespace std;


// This is our child class for flood emergencies
// It inherits the common information from Emergency
class FloodEmergency : public Emergency {

private:

    // Stores the water level of the flood in centimeters
    int waterLevelCm;

public:

    // Constructor for creating a flood emergency
    FloodEmergency(int id, const string& location,
                   int severity, int waterLevelCm);

    // Returns the type of emergency which is Flood
    // This function overrides the parent class function
    string getType() const override;

    // Displays the information of the flood emergency
    // We are overriding the display function from Emergency
    void display() const override;

};

#endif
