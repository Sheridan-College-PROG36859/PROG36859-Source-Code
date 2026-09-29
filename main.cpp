#include <iostream>

// Forward declare the functions that exist in separate files to keep things clean.

// ConstructorDestructorExamples.cpp
void ConstructorDestructorExamples();

// VectorExamples.cpp
void VectorExamples();

int main()
{
    // Invoke our Constructor/Destructor example
    ConstructorDestructorExamples();

    // Ivoke the Vector Example code that is in the VectorExamples.cpp file
    VectorExamples();
    
    return 0;
}