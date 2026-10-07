#include <iostream>

// Forward declare the functions that exist in separate files to keep things clean.

void CPPTemplates();

// CPPAbstract.cpp
void CPPAbstract();

// CPPDiamondPattern.cpp
void CPPDiamondPattern();

// ConstructorDestructorExamples.cpp
void ConstructorDestructorExamples();
void CallingConstructors();

// VectorExamples.cpp
void VectorExamples();

// void DoSomething(int value)
// {
//     value++;
//     DoSomething(value);
// }
//     int value = 0;
//     DoSomething(value);
//     std::cout << value << std::endl;

int main()
{

    CPPTemplates();

    // /CPPDiamondPattern();
    //CPPAbstract();

    // Invoke our Constructor/Destructor example
    //ConstructorDestructorExamples();
    //CallingConstructors();

    // Ivoke the Vector Example code that is in the VectorExamples.cpp file
    //VectorExamples();
    
    return 0;
}