#include <iostream>
#include <thread>
#include <mutex>

int value = 0;
std::mutex pause1;
std::mutex pause2;

void Foo(std::string str)
{
    int counter = 0;
    std::scoped_lock<std::mutex> guard1(pause1);
    while(value < 1000)
    {
        value++;
        counter++;
    }

    std::scoped_lock<std::mutex> guard2(pause2);
    std::cout << "Counter " << counter << std::endl;
}

void ThreadsExample()
{
    std::thread thread1(Foo, "Hello 1"); //Foo("Hello 1");
    std::thread thread2(Foo, "Hello 2"); //Foo("Hello 2");

    // this took a fair bit of time. maybe a stall

    if (thread1.joinable())
        thread1.join();

    if (thread2.joinable())
        thread2.join();
}