#include "Student.h"

Student::Student()
{
    std::cout << "Student Created" << std::endl;
}

void Student::Display()
{
    std::cout << "Age: " << age_ << std::endl;
    std::cout << "Student ID: " << studentId << std::endl;
}
