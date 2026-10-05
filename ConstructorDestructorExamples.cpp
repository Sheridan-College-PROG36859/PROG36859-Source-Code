#include <iostream>
#include "Vehicle.h"
#include "Bike.h"
#include "Truck.h"

// In this function we can see how calling constructors will work.
// The important part to this function is to look at the constructors
// themselves and using the debugger to step through how an object
// is created.
void CallingConstructors()
{
    Bike *bike2 = new Bike();
    Bike *bike = new Bike(2, "Red");
}

// This demonstrates the order of constructor/destructor calls
// We create the truck and bike as heap-allocated objects, and we delete them before
// we leave the function, otherwise we will leak memory!
void ConstructorDestructorExamples()
{
    std::cout << "This demonstrates the order of constructor/destructor calls" << std::endl;

    // Create a Truck
    Vehicle* truck = new Truck();
    std::cout << "Truck Has Engine: " << truck->HasEngine() << std::endl;

    std::cout << "Test " << std::endl;

    // Create a Bike
    Vehicle* bike = new Bike();
    std::cout << "Bike Has Engine: " << bike->HasEngine() << std::endl;

    // Now that we have stored the bike and 
    delete truck;
    delete bike;
}