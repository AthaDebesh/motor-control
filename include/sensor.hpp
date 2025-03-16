#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <string>
#include "revisions.hpp"

class Sensor : public Revisions{
public:
    // Constructor: Initializes the sensor with a unique identifier.
    Sensor(const std::string& id);

    // Destructor: Cleans up sensor resources.
    ~Sensor();

    // Reads the current temperature.
    double readTemperature();

    void setRev(std::string Rev) override;
    std::string getRev() override;

private:

    struct timespec sleep_time = {0, 100000000}; // 100ms (100,000,000 ns)

    double (Sensor::*readTemp)() = nullptr;

    double readTemperature1();
    double readTemperature2();

};

#endif // SENSOR_HPP
