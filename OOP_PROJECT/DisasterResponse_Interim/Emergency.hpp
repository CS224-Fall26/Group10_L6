
#ifndef EMERGENCY_HPP
#define EMERGENCY_HPP

#include <string>
using namespace std;

// Parent class for Fire and Flood emergencies
class Emergency {

private:
    int id;             // Unique ID of emergency
    string location;    // Location of emergency
    int severity;       // Severity level from 1 to 5
    string status;      // PENDING, ASSIGNED, RESOLVED
    int assignedUnitId; // -1 if no unit is assigned

public:

    // Constructor
    Emergency(int id, const string& location, int severity);

    // Destructor
    virtual ~Emergency();   //Here virtual makes sure that child object is deleted

    // Getter functions
    int getId() const;
    const string& getLocation() const;
    int getSeverity() const;
    string getStatus() const;
    int getAssignedUnitId() const;

    // Setter functions
    void setStatus(string newStatus);
    void setAssignedUnitId(int unitId);

    // Virtual functions
    virtual string getType() const = 0;
    virtual void display() const = 0;
};

#endif
