#include <iostream>
#include "Student.h"

class Temp
{
    int value = 0;
};

class Rectangle
{
    int length_ = 0;
    int width_ = 0;

public:
    Rectangle(int length, int width)
    {
        length_ = length;
        width_ = width;
    }

    // Overloading ++ operator.
    void operator++(int)
    {
        length_++;
        width_++;
    }
    
    inline Rectangle operator +(const Rectangle& rhs)
    {
        return Rectangle(length_ + rhs.length_, width_ + rhs.width_);
    }

    inline Rectangle operator =(const float& value)
    {
        return Rectangle(value, value);
    }

    inline Rectangle operator +(const float value)
    {
        return Rectangle(value + length_, value + width_);
    }
    
    friend inline float operator +(const float value, const Rectangle& rhs)
    {
        return value + rhs.length_ + value + rhs.width_;
    }

    // inline Rectangle operator +(const float value)
    // {
    //     return Rectangle(length_ + value, width_ + value);
    // }

    friend Rectangle operator +(const Rectangle& lhs, const Rectangle& rhs)
    {
        return Rectangle(lhs.length_ + rhs.length_, lhs.width_ + rhs.width_);
    }
};

int main()
{
    Student Student;
    Rectangle r1(1, 1);
    Rectangle r2(2, 2);

    r1++;

    r2 = 3.2f + r1;

    float f = (2.0f + r1);

    return 0;
}