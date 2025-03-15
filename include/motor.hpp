#ifndef MOTOR_HPP
#define MOTOR_HPP

#include <string>
#include "revisions.hpp"

class MotorController : public Revisions{
public:
    // Constructor: Initializes the motor controller with a unique identifier.
    MotorController(const std::string& id);

    // Destructor: Cleans up motor controller resources.
    ~MotorController();

    // Updates the motor position based on the given temperature.
    void updateMotorPosition(double temperature);

private:
    std::string uniqueID;
};

void MotorRightAction();
void MotorLeftAction();
void MotorStopAction();

#endif // MOTOR_HPP