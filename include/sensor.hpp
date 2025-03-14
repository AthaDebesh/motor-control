#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <string>
#include "revisions.hpp"

class TemperatureSensor : public Revisions{
private:
    std::string uniqueID;
public:
    // Constructor: Initializes the sensor with a unique identifier.
    TemperatureSensor(const std::string& id);

    // Destructor: Cleans up sensor resources.
    ~TemperatureSensor();

    // Reads the current temperature.
    double readTemperature();
};

#endif // SENSOR_HPP
