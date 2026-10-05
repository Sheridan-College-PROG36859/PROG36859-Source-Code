#pragma once

#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include <iostream>

class Vehicle
{
    int numWheels_ = 0;
    std::string colour_ = "";

protected:
    float speed = 0.0f;

public:
    Vehicle();
    Vehicle(int numWheels, const std::string& colour);

    virtual ~Vehicle();

    virtual bool HasEngine() = 0;
    virtual void DoSomething(int temp) {};
};

#endif
