#include <iostream>

// Here we have a template function that must have the same types for both
// parameters when we Invoke the function, note this must have both types the same
// or the compiler must be capable of implicity casting
// template <class T>
// void func(T a, T b)
// {
//     std::cout << "template function" << std::endl;
//     std::cout << "a = " << a << std::endl;
//     std::cout << "b = " << b << std::endl;
// }

// Here we have two different types that can be part of the template T and G
// This time when we attempt to pass in an int and char it will call the template
// because they are different types
template <class T, class G>
void func(T a, G b)
{
    std::cout << "template function" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    // Shows why we can't compile if we pass in T as std::string and G as int
    // we cannot do the following as an example 1 = "hello" + 1
    //b = a + b;
}

// a regular function that we can call that will be invoked as long as the types
// are the same or we have a template of the same function with just <T> and an
// implicit cast happens.
void func(int a, int b)
{
    std::cout << "non template function" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
}

// The example of a the std::vector class where we store type T
// Not complete and requires more code to finish up but demonstrates
// how we can make a pointer to a type
template <class T>
class Vector
{
    T *value_ = nullptr;
    int size_ = 0;
    int capacity_ = 0;

public:
    Vector()
    {
    }

    void push_back(T value)
    {
        // check allocations
        // realloc if needed
        // copy
        // put data at the back
    }
};

// Classic Node example where we store a T value
// Remember, T can also be a pointer....
template <class T>
class Node
{
    T value_;

public:
    Node(T value)
    {
        value_ = value;
    }

    void Display()
    {
        std::cout << value << std::endl;
    }
};

void CPPTemplates()
{
    Node<int> *node1 = new Node<int>(100);
    node1->Display();

    Node<bool> node2(true);
    node2.Display();

    int x = 0;
    int y = 0;

    std::string str = "Hello";

    // str is std::string
    //func(str, 1);

    // Invoke the template function because they are different
    //func(str, "World");

    func(str, "World");

    // These are literal == const char *
    func("Hello", "World");
    func(x, 'c');
    func(x, y);

}