#ifndef CLICKER_H
#define CLICKER_H

#include"libraries.h"

class Clicker
{
private:
    int count;
    std::mutex mtx;
    //std::atomic<int> count;
public:
    Clicker();
    void increment();
    void print();
};

#endif