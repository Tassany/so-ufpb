#include "./include/Fcfs.hpp"
#include "./include/Sjf.hpp"
#include "./include/Rr.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

int main()
{
    Fcfs fc;
    Sjf sjf;
    Rr rr;
    fc.readData();
    sjf.readData();
    // rr.readData();

    return 0;
}
