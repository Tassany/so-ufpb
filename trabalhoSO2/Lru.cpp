#include "./include/Lru.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <deque>
#include <cstring>
#include <algorithm>
using namespace std;

Lru::Lru()
{
}

void Lru::readData()
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
    int cont[numQuadros];
    memset(cont, 0, sizeof(cont));

    std::deque<int> lru;
    deque<int>::iterator it = lru.begin();
    int j = 0;
    for (int i = 0; i < numElementos; i++)
    {
        it = find(lru.begin(), lru.end(), aux[i + 1]);

        if (it != lru.end())
        {
            for (int j = 0; j < numQuadros; j++)
            {
                cont[j] = cont[j] + 1;
            }
            cont[it - lru.begin()] = 0;
            continue;
        }
        if ((lru.size() < numQuadros))
        {
            lru.push_back(aux[i + 1]);
            numFaltas++;

            continue;
        }
        else if ((find(lru.begin(), lru.end(), aux[i + 1]) == lru.end()))
        {
            int maior = cont[0];
            int posicao = 0;
            for (int j = 0; j < numQuadros; j++)
            {
                cont[j] = cont[j] + 1;
                if (cont[j] > maior)
                {
                    maior = cont[j];
                    posicao = j;
                }
            }

            lru[posicao] = aux[i + 1];
            cont[posicao] = 0;
            numFaltas++;
        }
    }

    std::cout << "lru " << endl;
    for (int i = 0; i < lru.size(); i++)
    {
        std::cout << lru[i] << endl;
    }
    std::cout << "Lru " << numFaltas << endl;
}