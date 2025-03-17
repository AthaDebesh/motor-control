#include <iostream>
#include <ctime>
#include "revisions.hpp"
#include "sensor.hpp"
#include "motor.hpp"
#include "realtime.hpp"

int main()
{
    std::string motorRev, sensorRev;
    std::string motorUID, sensorUID;

    std::cout << "Enter Motor Revision(A,B): ";
    std::cin >> motorRev;

    std::cout << "Enter Motor UniqueID : ";
    std::cin >> motorUID;

    std::cout << "Enter Sensor Revision(A,B): ";
    std::cin >> sensorRev;

    std::cout << "Enter Sensor UniqueID: ";
    std::cin >> sensorUID;

    Sensor TemperatureSensor(sensorUID);
    Motor MotorController(motorUID);

    Revisions* sensorRevision = &TemperatureSensor;
    Revisions* motorRevision = &MotorController;

    sensorRevision->setRev(sensorRev);
    motorRevision->setRev(motorRev);

    std::cout << "Motor Revision: " << sensorRevision->getRev() << std::endl;
    std::cout << "Sensor Revision: " << motorRevision->getRev() << std::endl;

    if(sensorRevision->getRev() == "Unknown" || motorRevision->getRev() == "Unknown")
    {
        std::cout << "Invalid Revision" << std::endl;
        return 0;
    }
    setRealTimePriority();
    setCPUAffinity();

    while (true)
    {
        
        MotorController.updateMotorRevision(TemperatureSensor.readTemperature());
    }

    return 0;
}