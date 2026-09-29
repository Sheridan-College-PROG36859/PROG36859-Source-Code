#include <iostream>
#include <vector>
#include "Vehicle.h"
#include "Bike.h"
#include "Truck.h"

// This demonstrates iterating through the vector as a const reference. We cannot change the vector
// but still 
void IteratingThroughAConstVector(const std::vector<Vehicle*>& vehicles)
{
    for(std::vector<Vehicle*>::const_iterator iter = vehicles.cbegin();
            iter != vehicles.end(); 
            ++iter)
    {
        std::cout << "This Vehicle Has Engine: " << (*iter)->HasEngine() << std::endl;
    }

    // Iterate using the foreach loop
    for (Vehicle* vehicle : vehicles)
    {
        std::cout << "This Vehicle Has Engine: " << vehicle->HasEngine() << std::endl;

        // Note we can still delete these objects....
        // Just because we can, doesn't mean we should, this can lead to some dangling
        // pointers that are left within the vector of vehicles
        //delete vehicle;
    }
}


// Examples on how to iterate through an array which was passed in as a reference
// NOTE: we can change the vector of vehicles here
void IteratingThroughAVector(std::vector<Vehicle*>& vehicles)
{
    // Simple iterator using the fully qualified name 
    for(std::vector<Vehicle*>::iterator iter = vehicles.begin();
            iter != vehicles.end(); 
            ++iter)
    {
        std::cout << "This Vehicle Has Engine: " << (*iter)->HasEngine() << std::endl;
    }

    // Simple iterator using auto 
    // auto = std::vector<Vehicle*>::iterator
    for(auto iter = vehicles.begin(); iter != vehicles.end(); ++iter)
    {
        std::cout << "This Vehicle Has Engine: " << (*iter)->HasEngine() << std::endl;
    }

    // To remove items we use the erase(iter) and the returned iter will be the next or end
    for(auto iter = vehicles.begin(); iter != vehicles.end(); )
    {
        std::cout << "This Vehicle Has Engine: " << (*iter)->HasEngine() << std::endl;
        // Remove anything that has an engine
        if ((*iter)->HasEngine())
        {
            delete (*iter);
            iter = vehicles.erase(iter);
        }
        else
        {
            ++iter;
        }
    }

    // When using the foreach style we do not have an iterator and therefore cannot manipulate the
    // vector. We mainly use this to iterate through a STL container to access the data directly
    for (Vehicle* vehicle : vehicles)
    {
        std::cout << "This Vehicle Has Engine: " << vehicle->HasEngine() << std::endl;
        //vehicle->SetColour(....)
    }
}

// Using the std::vector we can store as many Vehicles of different types
void VectorExamples()
{
    std::cout << std::endl << "Lets look at the Vector" << std::endl;

    // Using the std::vector we can store as many Vehicles of different types
    std::vector<Vehicle*> vehicles;
    vehicles.push_back(new Bike());
    vehicles.push_back(new Truck());
    vehicles.push_back(new Bike());
    vehicles.push_back(new Truck());

    // We pass the vehicles in and is a reference which avoids the copy
    IteratingThroughAVector(vehicles);
    IteratingThroughAConstVector(vehicles);

    // Clean up any memory in the vehicles 
    for (Vehicle* vehicle : vehicles)
    {
        delete vehicle;
    }    
    // Clear the vector
    vehicles.clear();
}