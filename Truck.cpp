#include "Truck.h"

Truck::Truck()
{
    std::cout << "Truck Created" << std::endl;
}

Truck::~Truck()
{
    std::cout << "Truck Destroyed" << std::endl;
}

bool Truck::HasEngine()
{
    return true;
}

void Truck::Display()
{
    Vehicle::Display();

    std::cout << "Truck details.... but doesn't have any" << std::endl;
}