#include "Bike.h"

Bike::Bike()
{
    std::cout << "Bike Created" << std::endl;

    gears = new int[10];
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