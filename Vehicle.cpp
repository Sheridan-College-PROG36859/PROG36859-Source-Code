#include "Vehicle.h"

Vehicle::Vehicle()
{
    std::cout << "Vehicle Created" << std::endl;
}

Vehicle::Vehicle(int numWheels, const std::string& colour)
{
    std::cout << "Vehicle Created with parameters" << std::endl;
    numWheels_ = numWheels;
    colour_ = colour;
}

Vehicle::~Vehicle()
{
    std::cout << "Vehicle Destroyed" << std::endl;
}

void Vehicle::Display()
{
    std::cout << "Vehicle Details" << std::endl;
    std::cout << "speed: " << speed << std::endl;
    std::cout << "numWheels: " << numWheels_ << std::endl;
    std::cout << "colour: " << colour_ << std::endl;
}

// Has been converted to pure virtual
// bool Vehicle::HasEngine()
// {
//     return true;
// }
