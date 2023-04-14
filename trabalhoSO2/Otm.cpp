#include "./include/Otm.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

Otm::Otm()
{
}

void Otm::readData()
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

    std::deque<int> otm;
    deque<int>::iterator it = otm.begin();
    int j = 0;
    for (int i = 0; i < numElementos; i++)
    {

        if ((find(otm.begin(), otm.end(), aux[i + 1]) != otm.end()))
        {
            continue;
        }
        if ((otm.size() < numQuadros))
        {
            otm.push_back(aux[i + 1]);
            numFaltas++;
            continue;
        }
        // se  aux[i + 1] nao estiver em otm substitui quem nao sera acessada pelo maior tempo
        else if ((find(otm.begin(), otm.end(), aux[i + 1]) == otm.end()))
        {
            int maior = 0;
            int posicao = 0;
            for (int k = 0; k < numQuadros; k++)
            {
                int aux2 = 0;
                for (int l = i + 1; l < numElementos; l++)
                {
                    if (otm[k] == aux[l])
                    {
                        break;
                    }
                    aux2++;
                }
                if (aux2 > maior)
                {
                    maior = aux2;
                    posicao = k;
                }
            }
            otm[posicao] = aux[i + 1];
            numFaltas++;
        }
    }

    // cout << "otm " << endl;
    // for (int i = 0; i < otm.size(); i++)
    // {
    //     cout << otm[i] << endl;
    // }
    cout << "Otm " << numFaltas << endl;
}