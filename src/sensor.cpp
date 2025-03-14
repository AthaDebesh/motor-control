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
    struct timespec sleep_time = {0, 100000000}; // 100ms (100,000,000 ns)
    clock_nanosleep(CLOCK_MONOTONIC, 0, &sleep_time, nullptr);

    // Generate random temperature between 80°C and 110°C
    double temperature = 80 + (std::rand() % 31); // 80 + (0 to 30)
    return temperature;
}
