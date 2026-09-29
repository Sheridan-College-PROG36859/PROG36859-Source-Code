#pragma once

#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>

// Initial class design for student Student:
// string name
// int age
// Consturcotr
// Display
class Student
{

private:
    int studentId_ = 0;
    int numGrades_ = 5;
    float *grades_ = nullptr;
    std::string name_ = "Bob";
    int age_ = 99;

public:
    Student();
    Student(int age);
    Student(int age, const std::string& name);
    Student(const std::string& name, int age);

    ~Student();

    // Copy Constructor
    Student(const Student &other);

    // The assignment operator will use the following example:
    //      student_1 = student;
    //      student = student; // this == other
    //
    // where student is other and student_1 is this. We need
    // to write the assignment operator whenever we have ownershipe
    // of pointers to make sure that when one object is deleted it does
    // not leave dangling pointers
    Student& operator=(const Student &other);

    // Example of a functor in CPP and in header
    void operator ()(const std::string& name)
    {
        name_ = name;
    }
    
    // Example of a functor implemented in the CPP
    int operator ()(int age);

    void Display();
};

#endif
