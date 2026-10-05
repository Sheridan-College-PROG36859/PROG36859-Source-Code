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

bool Vehicle::HasEngine()
{
    return true;
}
