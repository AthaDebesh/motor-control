#ifndef MOTOR_HPP
#define MOTOR_HPP

#include <string>
#include "revisions.hpp"

class Motor : public Revisions{
public:
    // Constructor: Initializes the motor controller with a unique identifier.
    Motor(const std::string& id);

    // Destructor: Cleans up motor controller resources.
    ~Motor();

    // Updates the motor position based on the given temperature.
    void updateMotorRevision(double temperature);

    void setRev(std::string Rev);
    std::string getRev();

private:

    void (Motor::*MotorRev)(double);

    void MotorRevision1(double);
    void MotorRevision2(double);

};

void MotorRightAction();
void MotorLeftAction();
void MotorStopAction();

#endif // MOTOR_HPP