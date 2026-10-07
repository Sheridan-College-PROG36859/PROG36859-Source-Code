#include <iostream>

class A
{
public:
    int a_value_ = 0;
};

class B : public A
{
public:
    int b_value_ = 0;
};

class C : public A
{
public:
    int c_value_ = 0;
};

class D : public B, C
{
public:
    int d_value_ = 0;
};

void CPPDiamondPattern()
{
    D *ptr = new D();

    ptr->B::a_value_ = 5;
    //ptr->C::a_value_ = 5; ???
    ((C*)ptr)->a_value_ = 5;

    delete ptr;
}