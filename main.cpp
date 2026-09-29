// Write the main function that will output Hello World using std::cout
#include <iostream>
#include <string>

// Initial class design for student Student
// IT has:
    // string name
    // int age
    // Consturcotr
    // Display
class Student
{

private:
    float *grades_ = nullptr;
    std::string name_ = "Bob";
    int age_ = 99;

public:
    Student()
    {
        // C style for allocatint 5 grades
        //grades_ = (float*)malloc(sizeof(float) * 5);

        // C++ style for allocating 5 grades. You should
        // use this style.
        grades_ = new float[5];
    }

    ~Student()
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

    Student(int age)
    {
        std::cout << "Student with age created" << std::endl;

        age_ = age;
    }

    Student(int age, std::string name)
    {
        name_ = name;
        age_ = age;
    }

    Student(std::string name, int age)
    {
        name_ = name;
        age_ = age;
    }

    // Copy Constructor
    Student(const Student &other)
    {
        // we do what we do below in the assignment operator
    }

    // The assignment operator will use the following example:
    //      student_1 = student;
    //      student = student; // this == other
    //
    // where student is other and student_1 is this. We need
    // to write the assignment operator whenever we have ownershipe
    // of pointers to make sure that when one object is deleted it does
    // not leave dangling pointers
    Student& operator=(const Student &other)
    {
        // if we are trying to assign ourself then early out no need
        if (this == &other)
        {
            return *this;
        }

        // Otherwise, we copy the aga_ and name_

        this->age_ = other.age_;
        this->name_ = other.name_;

        // then we need to delete grades_ if they exist
        if (grades_ != nullptr)
        {
            delete grades_;
            grades_ = nullptr;  
        }

        // Finally create and copy the grades from other
        if (other.grades_ != nullptr)
        {
            grades_ = new float[5];
            //memcpy(grades_, other.grades_, 5 * sizeof(float));
            for(int i = 0; i < 5; i++)
            {
                grades_[i] = other.grades_[i];
            }
        }

        return *this;
    }

    int operator ()(int age)
    {
        age_ = age;
        return age_ + 5;
    }

    void Display()
    {
        std::cout << name_ << " : " << age_ << std::endl;
    }
};


void DoFunctor()
{
    Student student;
    student(5);
}

// Example of creating an array of 5 students which are pointers
// We then allocate a new student for each element. The elements in
// the array are pointers (a number which is the memory address for
// the student object). We then delete each student in the array.
// Remember the students[5] variable is a stack-allocated object (local variable)
// and does not need to be deleted because this will be done
// when we leave the function like any other local variable
// void DoSomething()
// {
//     Student* students[5];
//     students[0] = new Student();
//     students[1] = new Student();
//     students[2] = new Student();
//     students[3] = new Student();
//     students[4] = new Student();
//     delete students[0];
//     delete students[1];
//     delete students[2];
//     delete students[3];
//     delete students[4];
// }

// In this example we allocate a single student on the Heap. We
// immediately delete it and set the pointer to NULL. It is good
// practice and encouraged to do this always to ensure you do not access
// memory that has already been deleted. We can see this by using
// the if check to make sure the pointer is not NULL before calling
// Display 
// void DoSomething()
// {
//     Student *student_1 = new Student();
//     delete student_1;
//     student_1 = nullptr;
//     if (student_1 != nullptr)
//     {
//         student_1->Display();
//     }
// }

void DoSomething()
{
    int x = 5;
    int y = 6;
    x = y;
    x = x;

    Student student;
    student.Display();

    //student = student;

    //Student student_1 = student;
    Student student_1(student);
}

// In the main create a Student and call Display
int main()
{
    Student student(5);

    DoSomething();

    // Create a student object on the Heap using thew new operator
    // which invokes the default construtor.
    // Because this is a pointer we use the -> notation to access
    // the Display function.
    // We also delete the student to release the memory from the heap
    // Student* student_2 = new Student();
    // student_2->Display();    
    // delete student_2;

    // Invoke the DoSomething function
    //DoSomething();

    // Create a stack-allocated object (local variable) called
    // student_1 which uses the default constructor. Remember
    // if we have a parameter constructor we must write our own
    // default to use this otherwise C++ will not make one
    // Because this is not a pointer we use the . to access
    // the Display function.
    // Student student_1;
    // student_1.Display();

    // Create a stack-allocated object (local variable) called
    // student which uses the parameter constructor that takes
    // and int. Because this is not a pointer we use the . to 
    // access the Display function.
    // As well, the std::cout fails because name_ is private
    // Student student(5);
    // student.Display();
    //std::cout << student.name_ << std::endl;

    // Example of creating 5 new student objects on the Heap.
    // These student objects are then deleted to make sure we 
    // manage our memory and do not leak
    // for(int i = 0; i < 5; i++)
    // {
    //     Student *pStudent = new Student();
    //     delete pStudent;
    // }

    return 0;
}