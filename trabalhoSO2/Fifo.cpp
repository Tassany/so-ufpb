#include "./include/Fifo.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

Fifo::Fifo()
{
}

void Fifo::readData()
{

    int numQuadros = 0;
    int numElementos = 0;
    int numFaltas = 0;
    int i = 0;

    vector<int> aux;

    // lendo o arquivo de instancias
    ifstream input("instances.txt");

    while (!input.eof())
    {
        input >> i;
        aux.push_back(i);
        ++numElementos;
    }
    numElementos = numElementos - 1;
    numQuadros = aux[0];

    std::deque<int> fifo;
    deque<int>::iterator it = fifo.begin();
    int j = 0;
    for (int i = 0; i < numElementos; i++)
    {

        if ((find(fifo.begin(), fifo.end(), aux[i + 1]) != fifo.end()))
        {
            continue;
        }

        if ((fifo.size() < numQuadros))
        {
            fifo.push_back(aux[i + 1]);
            numFaltas++;
            continue;
        }
        else if ((find(fifo.begin(), fifo.end(), aux[i + 1]) == fifo.end()))
        {
            fifo[j] = aux[i + 1];
            j++;
            numFaltas++;
            if (j >= numQuadros)
            {
                j = 0;
            }
        }
    }

    cout << "Fifo " << numFaltas << endl;
}