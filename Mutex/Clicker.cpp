#include "Clicker.h"

Clicker::Clicker()
{
    count = 0;
}

void Clicker::increment()
{
    for (int i = 0; i < 100000; i++)
    {
        mtx.lock();
        count++;
        mtx.unlock();
    }
}

void Clicker::print()
{
    std::cout << count << std::endl;
}
