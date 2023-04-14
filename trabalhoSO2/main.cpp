#include "./include/Fifo.hpp"
#include "./include/Otm.hpp"
#include "./include/Lru.hpp"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

int main()
{
    Fifo fifo;
    Otm otm;
    Lru lru;

    lru.readData();
    fifo.readData();
    otm.readData();

    return 0;
}
