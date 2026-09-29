//NOTE: This file is not part of the tasks.json and is here for example code
#include "Student.h"

// Example of creating an array of 5 students which are pointers
// We then allocate a new student for each element. The elements in
// the array are pointers (a number which is the memory address for
// the student object). We then delete each student in the array.
// Remember the students[5] variable is a stack-allocated object (local variable)
// and does not need to be deleted because this will be done
// when we leave the function like any other local variable
void ArrayOfStudentObjects()
{
    Student* students[5];
    students[0] = new Student();
    students[1] = new Student();
    students[2] = new Student();
    students[3] = new Student();
    students[4] = new Student();
    delete students[0];
    delete students[1];
    delete students[2];
    delete students[3];
    delete students[4];
}

// In this example we allocate a single student on the Heap. We
// immediately delete it and set the pointer to NULL. It is good
// practice and encouraged to do this always to ensure you do not access
// memory that has already been deleted. We can see this by using
// the if check to make sure the pointer is not NULL before calling
// Display 
void HealAllocatedStudent()
{
    Student *student_1 = new Student();
    delete student_1;
    student_1 = nullptr;
    if (student_1 != nullptr)
    {
        student_1->Display();
    }
}

// An example of the basic int using the copy
// we can see how the Student is using the Assignment operator
// and copy constructor
void AssignmentOperatorAndCopyConstructor()
{
    int x = 5;
    int y = 6;
    x = y;

    Student student;
    student.Display();

    Student student_1 = student;
    Student student_2(student);
}

// In the main create a Student and call Display
int ExampleCodeWorkingWithStudent()
{
    Student student(5);

    AssignmentOperatorAndCopyConstructor();

    // Create a student object on the Heap using thew new operator
    // which invokes the default construtor.
    // Because this is a pointer we use the -> notation to access
    // the Display function.
    // We also delete the student to release the memory from the heap
    Student* student_1 = new Student();
    student_1->Display();    
    delete student_1;

    // Create a stack-allocated object (local variable) called
    // student_1 which uses the default constructor. Remember
    // if we have a parameter constructor we must write our own
    // default to use this otherwise C++ will not make one
    // Because this is not a pointer we use the . to access
    // the Display function.
    Student student_2;
    student_2.Display();

    // Create a stack-allocated object (local variable) called
    // student which uses the parameter constructor that takes
    // and int. Because this is not a pointer we use the . to 
    // access the Display function.
    // As well, the std::cout fails because name_ is private
    Student student_3(5);
    student_3.Display();
    std::cout << student_3.GetName() << std::endl;

    // Example of creating 5 new student objects on the Heap.
    // These student objects are then deleted to make sure we 
    // manage our memory and do not leak
    for(int i = 0; i < 5; i++)
    {
        Student *pStudent = new Student();
        delete pStudent;
    }

    return 0;
}