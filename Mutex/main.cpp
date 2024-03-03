#include "Clicker.h"
#include "libraries.h"

int main()
{
    Clicker clicker;
    std::thread thread1 = std::thread(&Clicker::increment, std::ref(clicker));
    std::thread thread2 = std::thread(&Clicker::increment, std::ref(clicker));
    thread1.join();
    thread2.join();
    clicker.print();
}
