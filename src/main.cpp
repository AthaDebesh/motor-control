#include <iostream>
#include <ctime>
#include "sensor.hpp"
#include "motor.hpp"
#include "realtime.hpp"

int main()
{
    std::string motorRev, sensorRev;

    std::cout << "Enter Motor Revision : ";
    std::cin >> motorRev;

    std::cout << "Enter Sensor Revision : ";
    std::cin >> sensorRev;

    setRealTimePriority();
    setCPUAffinity();

    TemperatureSensor sensor("ABC123");
    MotorController motor("XYZ789");

    sensor.setRev(sensorRev);
    motor.setRev(motorRev);

    std::cout << "Motor Revision: " << motor.getRev() << std::endl;
    std::cout << "Sensor Revision: " << sensor.getRev() << std::endl;

    while (true)
    {
        motor.updateMotorPosition(sensor.readTemperature());
    }

    return 0;
}