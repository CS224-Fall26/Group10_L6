
#ifndef FIRE_TRUCK_HPP
#define FIRE_TRUCK_HPP

#include "RescueUnit.hpp"

using namespace std;


// This is our child class for Fire Trucks
// It inherits all the common information from RescueUnit
class FireTruck : public RescueUnit {

public:

    // Constructor to set the ID and name of fire truck
    FireTruck(int id, const string& name);


    // This tells us the type of rescue unit
    // We are overriding the parent class function
    string getType() const override;


    // This checks whether our fire truck can handle an emergency
    // It should only handle Fire emergencies
    bool canHandle(const Emergency& emergency) const override;


    // This displays the information of the fire truck
    void display() const override;

};

#endif
