#include "motor.hpp"
#include <iostream>

MotorController::MotorController(const std::string &uniqueID)
{
    std::cout << "MotorController (" << uniqueID << ") created." << std::endl;
}

MotorController::~MotorController()
{
}

void MotorController::updateMotorPosition(double temperature)
{
    if (temperature < 85.0) {
        std::cout << "Temperature: " << temperature 
                  << "°C - Motor (" << uniqueID 
                  << ") rotates to the right" << std::endl;
    } else if (temperature < 105.0) { // 85°C ≤ Temperature < 105°C
        std::cout << "Temperature: " << temperature 
                  << "°C - Motor (" << uniqueID 
                  << ") rotates to the left" << std::endl;
    } else { // Temperature ≥ 105°C
        std::cout << "Temperature: " << temperature 
                  << "°C - Motor (" << uniqueID 
                  << ") stops immediately" << std::endl;
    }
}
