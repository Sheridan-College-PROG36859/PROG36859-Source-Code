#include "Bike.h"

Bike::Bike()
    : Vehicle(2, "Red")
{
    std::cout << "Bike Created" << std::endl;

    gears = new int[10];
}

Bike::Bike(int numWheels, const std::string& colour)
    : Vehicle(numWheels, colour)
{
    std::cout << "Bike Created with parameters" << std::endl;
}


Bike::~Bike()
{
    std::cout << "Bike Destroyed" << std::endl;

    delete gears;
}

bool Bike::HasEngine()
{
    return false;
}