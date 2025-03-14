#include <iostream>
#include <ctime>
#include "sensor.hpp"
#include "motor.hpp"
#include "realtime.hpp"

int main()
{
    setRealTimePriority();
    setCPUAffinity();

    TemperatureSensor sensor("ABC123");
    MotorController motor("XYZ789");

    while (true)
    {
        motor.updateMotorPosition(sensor.readTemperature());
    }

    return 0;
}