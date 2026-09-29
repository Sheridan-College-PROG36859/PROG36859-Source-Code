// Write the main function that will output Hello World using std::cout
#include <iostream>
#include <string>

// Create a class called Student
// IT has:
    // string name
    // int age
    // Consturcotr
    // Display

class Student
{
private:
    std::string name_;
    int age_;

public:
    Student()
    {
        name_ = "Bob";
        age_ = 99;
    }

    void Display()
    {
        std::cout << name_ << " : " << age_ << std::endl;
    }
};

// In the main create a Student and call Display
int main()
{
    Student student;
    student.Display();

    for(int i = 0; i < 5; i++)
    {
        Student *pStudent = new Student();
        delete pStudent;
    }

    //std::cout << student.name_ << std::endl;

    return 0;
}