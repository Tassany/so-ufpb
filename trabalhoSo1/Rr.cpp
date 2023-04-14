#include "./include/Rr.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

Rr::Rr()
{
    numProcess = 0;
}

int Rr::getArrive(int numProcess)
{
    return arrive[numProcess];
}

void Rr::readData()
{

    ifstream input("instances.txt");
    int i = 0;
    int numProcess = 0; // quantidade de processos
    int currentTime = 0;
    int minProcessDur;
    int currentIndex = 0;
    double totalWaitTime = 0;
    double totalArriveTime = 0;
    double totalReturnTime = 0;
    vector<int> newDur;
    vector<int> firstTime;
    bool hasProcessToRun = true;
    int quantum = 2;
    int lastCurrentTime = 0;

    // lendo o arquivo de instancias
    while (!input.eof())
    {
        input >> i;
        arrive.push_back(i);
        input >> i;
        processDur.push_back(i);
        numProcess++;
    }

    for (i = 0; i < numProcess; i++)
    {
        firstTime.push_back(false);
    }

    // ############### Ordenação ###################
    minProcessDur = processDur[0];
    newDur.push_back(0);

    while (hasProcessToRun)
    {
        lastCurrentTime = newDur[newDur.size() - 1];
        for (int i = 0; i < numProcess; i++)
        {
            if (arrive[i] <= currentTime)
            {
                if (processDur[i] >= quantum)
                {
                    processDur[i] -= quantum;
                    currentTime += quantum;
                    newDur.push_back(currentTime);
                }
                else
                {
                    if (processDur[i] == 0)
                        break;
                    currentTime += processDur[i];
                    processDur[i] = 0;
                    newDur.push_back(currentTime);
                }
            }
        }
        if (newDur[newDur.size() - 1] == lastCurrentTime)
        {
            hasProcessToRun = false;
            if (arrive[i] <= currentTime)
            {
                if (processDur[i] >= quantum)
                {
                    processDur[i] -= quantum;
                    currentTime += quantum;
                    newDur.push_back(currentTime);
                }
                else
                {
                    if (processDur[i] == 0)
                        break;
                    currentTime += processDur[i];
                    processDur[i] = 0;
                    newDur.push_back(currentTime);
                }
            }
        }
    }

    // #################################################

    // ############### Tempo de espera ###################
    numProcess = newDur.size();
    for (int i = 0; i < numProcess - 1; i++)
    {
        waitTime.push_back(newDur[i]);
    }

    // for (int i = 0; i < waitTime.size(); i++)
    //     std::cout << "Wait time :  " << waitTime[i] << endl;
    // std::cout << '\n';

    for (i = 0; i < numProcess - 1; i++)
    {
        totalWaitTime = totalWaitTime + waitTime[i];
    }

    // #################################################

    // ############### Tempo de retorno ###################

    // for (int i = 0; i < numProcess; i++)
    // {
    //     totalReturnTime = totalReturnTime + newDur[i];
    // }

    // totalReturnTime = totalReturnTime - totalArriveTime;

    // totalReturnTime = totalReturnTime / (numProcess - 1);

    // ####################################################

    std::cout << "Rr " << totalReturnTime << " " << totalWaitTime << endl;
}

int Rr::getProcessDur(int numProcess)
{
    return processDur[numProcess];
}
