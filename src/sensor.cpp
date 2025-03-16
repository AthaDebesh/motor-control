#include "sensor.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

Sensor::Sensor(const std::string &uniqueID): Revisions(uniqueID)
{
    std::cout << "TemperatureSensor (" << uniqueID << ") created." << std::endl;
    std::srand(std::time(nullptr));
}

Sensor::~Sensor()
{
}

double Sensor::readTemperature()
{
    return readTemp ? (this->*readTemp)() : -1;
}

void Sensor::setRev(std::string Rev)
{
    Revision_id = Rev;

    if (Revision_id == "A")
    {
        readTemp = &Sensor::readTemperature1;
    }
    else if (Revision_id == "B")
    {
        readTemp = &Sensor::readTemperature2;
    }
    else
    {
        Revision_id = "Unknown";
        readTemp = nullptr;
    }
}

std::string Sensor::getRev()
{
    return Revision_id;
}

double Sensor::readTemperature1()
{
    clock_nanosleep(CLOCK_MONOTONIC, 0, &sleep_time, nullptr);

    // Generate random temperature between 80°C and 110°C
    double temperature = 80 + (std::rand() % 31); // 80 + (0 to 30)
    return temperature;
    
}

double Sensor::readTemperature2()
{
    clock_nanosleep(CLOCK_MONOTONIC, 0, &sleep_time, nullptr);

    // Generate random temperature between 75°C and 115°C
    double temperature = 75 + (std::rand() % 41); // 75 + (0 to 40)
    return temperature;
    
}
