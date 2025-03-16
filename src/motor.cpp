#include "motor.hpp"
#include <iostream>

Motor::Motor(const std::string &uniqueID):Revisions(uniqueID)
{
    std::cout << "MotorController (" << uniqueID << ") created." << std::endl;
}

Motor::~Motor()
{
}

void Motor::updateMotorRevision(double temperature)
{
    (this->*MotorRev)(temperature);
    
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

void Motor::setRev(std::string Rev)
{
    Revision_id = Rev;

    if(Revision_id == "A")
    {
        MotorRev = &Motor::MotorRevision1;
        
    }
    else if(Revision_id == "B")
    {
        MotorRev = &Motor::MotorRevision2;
    }
    else
    {
        Revision_id = "Unknown";
        std::cout << "Invalid Motor Revision" << std::endl;
    }
}

std::string Motor::getRev()
{
    return Revision_id;
}

void Motor::MotorRevision1(double temperature)
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

void Motor::MotorRevision2(double temperature)
{
    if (temperature < 80.0) {
        std::cout << "Temperature: " << temperature << "°C ";
        MotorRightAction();
    } else if (temperature < 110.0) { // 80°C ≤ Temperature < 110°C
        std::cout << "Temperature: " << temperature << "°C ";
        MotorLeftAction();
    } else { // Temperature ≥ 110°C
        std::cout << "Temperature: " << temperature << "°C ";
        MotorStopAction();
    }
}
