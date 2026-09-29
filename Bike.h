#pragma once

#ifndef _BIKE_H_
#define _BIKE_H_

#include <iostream>
#include "Vehicle.h"

class Bike : public Vehicle
{
    int* gears = nullptr;
    
public:
    Bike();
    ~Bike();

    bool HasEngine() override;
};

#endif