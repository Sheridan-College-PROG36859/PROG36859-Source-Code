#include <iostream>
#include "Student.h"
#include "Vehicle.h"
#include "Bike.h"
#include "Truck.h"

// Forward declare the function VectorExamples. The compiler will compile the VectorExamples.cpp
// and will link the function there to the one we call in the main.
void VectorExamples();


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

int main()
{
    // Invoke our Constructor/Destructor example
    ConstructorDestructorExamples();

    // Ivoke the Vector Example code that is in the VectorExamples.cpp file
    VectorExamples();
    
    return 0;
}