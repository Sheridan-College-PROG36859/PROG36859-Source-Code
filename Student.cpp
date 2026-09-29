#include "Student.h"

Student::Student()
{
    std::cout << "Student Created" << std::endl;

    // C style for allocatint 5 grades
    // grades_ = (float*)malloc(sizeof(float) * 5);

    // C++ style for allocating 5 grades. You should
    // use this style.
    grades_ = new float[numGrades_];
}

Student::Student(int age)
{
    std::cout << "Student with age created" << std::endl;
    age_ = age;
}

Student::Student(int age, const std::string &name)
{
    name_ = name;
    age_ = age;
}

Student::Student(const std::string &name, int age)
{
    name_ = name;
    age_ = age;
}

// Copy Constructor
Student::Student(const Student &other)
{
    this->age_ = other.age_;
    this->name_ = other.name_;
    this->numGrades_ = other.numGrades_;
    // Note grades_ is already null so no need to set it to null again

    // Finally create and copy the grades from other if grades in other exist
    if (other.grades_ != nullptr)
    {
        grades_ = new float[5];
        for (int i = 0; i < 5; i++)
        {
            grades_[i] = other.grades_[i];
        }
    }
}

// The assignment operator will use the following example:
//      student_1 = student;
//      student = student; // this == other
//
// where student is other and student_1 is this. We need
// to write the assignment operator whenever we have ownershipe
// of pointers to make sure that when one object is deleted it does
// not leave dangling pointers
Student &Student::operator=(const Student &other)
{
    // if we are trying to assign ourself then early out no need
    if (this == &other)
    {
        return *this;
    }

    // Otherwise, we copy the numGrades_, age_ and name_

    this->age_ = other.age_;
    this->name_ = other.name_;
    this->numGrades_ = other.numGrades_;

    // then we need to delete grades_ if they exist
    if (grades_ != nullptr)
    {
        delete grades_;
        grades_ = nullptr;
    }

    // Finally create and copy the grades from other
    if (other.grades_ != nullptr)
    {
        grades_ = new float[numGrades_];
        // memcpy(grades_, other.grades_, numGrades_ * sizeof(float));
        for (int i = 0; i < numGrades_; i++)
        {
            grades_[i] = other.grades_[i];
        }
    }

    return *this;
}

Student::~Student()
{
    // We make sure grades_ is not null before deleting.
    if (grades_ != nullptr)
    {
        // Although we think of grades as an array it is technically not.
        // grades_ is a pointer to some memory allocated and therefore
        // we do not use the delete [] grades_; syntax because we are
        // deallocating a data from a pointer
        delete grades_;
    }
}

// Example of a functor implemented in the CPP
int Student::operator()(int age)
{
    age_ = age;
    return age_ + 5;
}

void Student::Display()
{
    std::cout << "Age: " << age_ << std::endl;
    std::cout << "Student ID: " << studentId_ << std::endl;
}
