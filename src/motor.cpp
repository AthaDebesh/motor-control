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
        std::cout << "Temperature: " << temperature << "°C ";
        MotorRightAction();
    } else if (temperature < 105.0) { // 85°C ≤ Temperature < 105°C
        std::cout << "Temperature: " << temperature << "°C ";
        MotorLeftAction();
    } else { // Temperature ≥ 105°C
        std::cout << "Temperature: " << temperature << "°C ";
        MotorStopAction();
    }
}

void MotorRightAction()
{
    std::cout <<"- Motor rotates to the right" << std::endl;  // Signal sent to motor to rotate right
}

void MotorLeftAction()
{
    std::cout <<"- Motor rotates to the left" << std::endl;  // Signal sent to motor to rotate left
}

void MotorStopAction()
{
    std::cout <<"- Motor stop immediately" << std::endl;    // Signal sent to motor to stop motor
}
