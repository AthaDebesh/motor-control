#include <iostream>
#include <ctime>
#include "sensor.hpp"
#include "motor.hpp"
#include "realtime.hpp"

int main()
{
    setRealTimePriority();

    TemperatureSensor sensor("ABC123");
    MotorController motor("XYZ789");

    struct timespec next;
    clock_gettime(CLOCK_MONOTONIC, &next);
    const long interval_ns = 100 * 1000000;

    while (true)
    {
        motor.updateMotorPosition(sensor.readTemperature());

        next.tv_nsec += interval_ns;
        if (next.tv_nsec >= 1000000000) {
            next.tv_sec += next.tv_nsec / 1000000000;
            next.tv_nsec %= 1000000000;
        }

        clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &next, nullptr);
    }

    return 0;
}