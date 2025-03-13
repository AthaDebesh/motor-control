#include "sensor.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

TemperatureSensor::TemperatureSensor(const std::string &uniqueID)
{
    std::cout << "TemperatureSensor (" << uniqueID << ") created." << std::endl;

    std::srand(std::time(nullptr));
}

TemperatureSensor::~TemperatureSensor()
{
}

double TemperatureSensor::readTemperature()
{
    return 80.0 + (std::rand()%31);
}
