#include <iostream>

class Rectangle
{
    float width_ = 0.0f;
    float length_ = 0.0f;

public:
    Rectangle() {}
    Rectangle(float width, float length)
    {
        width_ = width;
        length_ = length;
    }

    Rectangle operator+(const Rectangle& rhs)
    {
        return Rectangle(this->width_ + rhs.width_, this->length_ + rhs.length_);
    }
};

void CPPOeratorOverloading()
{
    Rectangle rect1(5, 10);
    Rectangle rect2(20, 50);

    // rect1.operator+(rect2)
    Rectangle rect3 = rect1 + rect2;
    
    //std::cout << rect3;
}