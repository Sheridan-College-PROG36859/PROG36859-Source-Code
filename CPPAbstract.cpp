#include <iostream>
#include "Vehicle.h"
#include "Bike.h"
#include "Truck.h"

class IInterface
{
    virtual void InterfaceFunction() = 0;
};

class AbstractClass
{
public:
    virtual void AbstractFunction() = 0;
};

class DerivedFromAbstract : public AbstractClass, IInterface
{
public:
    void AbstractFunction() override
    {
    };

    void InterfaceFunction() override
    {
    }
};

void CPPAbstract()
{
    //AbstractClass *ptr1 = new AbstractClass();
    DerivedFromAbstract *ptr2 = new DerivedFromAbstract();
    ptr2->AbstractFunction();
    
    AbstractClass *ptr3 = new DerivedFromAbstract();
    ptr3->AbstractFunction();
}