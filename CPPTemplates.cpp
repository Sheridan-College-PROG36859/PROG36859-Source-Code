#include <iostream>

//template <typename T>
// template <class T>
// void func(T a, T b)
// {
//     std::cout << "template function" << std::endl;
//     std::cout << "a = " << a << std::endl;
//     std::cout << "b = " << b << std::endl;
// }

template <class T, class G>
void func(T a, G b)
{
    std::cout << "template function" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    b = a + b;
}

void func(int a, int b)
{
    std::cout << "non template function" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
}

void CPPTemplates()
{
    int x = 0;
    int y = 0;

    std::string str = "Hello";

    // str is std::string
    //func(str, 1);

    // These are literal == const char *
    func("Hello", "World");
    func(x, 'c');
    func(x, y);

}