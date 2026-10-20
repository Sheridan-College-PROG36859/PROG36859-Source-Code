#include <iostream>

class Circle
{
    float radius_ = 10.0f;

    // By making Rectangle a friend class, it will allow the Rectangle class
    // access to all the Circle methods and functions even the private ones
    // NOTE: be careful using this practice and try to avoid it
    //friend class Rectangle;

public:
    float GetRadius() const { return radius_; }
};


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
    
    friend Rectangle operator+(const Circle& lhs, const Rectangle& rhs)
    {
        // Here we use the friend class in Circle allowing Rectangle access to
        // their private methods and variables
        //return Rectangle(lhs.radius_ + rhs.width_, lhs.radius_ + rhs.length_);

        // This line uses the GetRadius function and is the right way
        return Rectangle(lhs.GetRadius() + rhs.width_, lhs.GetRadius() + rhs.length_);
    }

    Rectangle operator+(const float& rhs)
    {
        return Rectangle(this->length_ + rhs, this->width_ + rhs);
    }

    bool operator==(const Rectangle& rhs)
    {
        return (this->length_ == rhs.length_ && this->width_ == rhs.width_);
    }

    Rectangle operator-(const Rectangle& rhs)
    {
        return Rectangle(this->width_ - rhs.width_, this->length_ - rhs.length_);
    }

    Rectangle operator+(const Rectangle& rhs)
    {
        return Rectangle(this->width_ + rhs.width_, this->length_ + rhs.length_);
    }

    friend Rectangle operator+(const float& lhs, const Rectangle& rhs)
    {
        return Rectangle(lhs + rhs.width_, lhs + rhs.length_);
    }

    friend std::ostream& operator<<(std::ostream& os, const Rectangle& rhs)
    {
        os << "Rect Width " << rhs.width_ << std::endl;
        os << "Rect Length " << rhs.length_ << std::endl;
        return os;
    }

    Rectangle& operator++(int)
    {
        this->width_ += 1.0f;
        this->length_ += 1.0f;
        return *this;
    }

    Rectangle& operator+=(const float rhs)
    {
        this->width_ += rhs;
        this->length_ += rhs;
        return *this;
    }
};

void CPPOeratorOverloading()
{
    Rectangle rect1(5, 10);
    Rectangle rect2(20, 50);

    rect1++;
    rect1 += 5.0f;
    //rect1 += rect1;

    // rect1.operator+(rect2)
    Rectangle rect3 = rect1 + rect2;

    // rect1.operator-(rect2)
    Rectangle rect4 = rect1 - rect2;
   
    // rect1.operator==(rect2)
    bool value = rect1 == rect2;
    if (rect1 == rect2) {}

    // rect1.operator+(500.0f)
    Rectangle rect5 = rect1 + 500.0f;

     //operator+(500.0f + rect1)
    Rectangle rect6 = 500.0f + rect1;

    std::cout << rect6;

    Circle c1;

    Rectangle rect7 = c1 + rect1;

    // This will not compile because we need another operator in the Circle class
    //Circle c2 = c1 + rect1;

    //std::cout << rect3;
}