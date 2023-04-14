#include "./include/Fcfs.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

Fcfs::Fcfs()
{
    numProcess = 0;
}

int Fcfs::getArrive(int numProcess)
{
    return arrive[numProcess];
}

void Fcfs::readData()
{

    ifstream input("instances.txt");
    int i = 0;
    int numProcess = 0; // quantidade de processos
    double totalWaitTime = 0;
    double totalReturnTime = 0;
    double totalArriveTime = 0;

    // lendo o arquivo de instancias
    while (!input.eof())
    {
        input >> i;
        arrive.push_back(i);
        input >> i;
        processDur.push_back(i);
        numProcess++;
    }

    // ############### Tempo de espera ###################

    waitTime.push_back(0);
    for (int i = 0; i < numProcess; i++)
    {
        waitTime.push_back(waitTime[i] + processDur[i]);
    }
    for (int i = 0; i < numProcess; i++)
    {
        waitTime[i] = waitTime[i] - arrive[i];
    }

    for (int i = 0; i < processDur.size(); i++)
    {
        totalWaitTime = waitTime[i] + totalWaitTime;
    }

    totalWaitTime = totalWaitTime / numProcess;

    // #################################################

    // ############### Tempo de retorno ###################

    for (int i = 0; i < waitTime.size(); i++)
    {
        totalReturnTime = totalReturnTime + waitTime[i];
    }

    totalReturnTime = totalReturnTime / (numProcess);

    // #################################################

    // ############### Tempo de resposta ###################

    // Por não ter preempção o tempo de resposta é o mesmo que o tempo de espera

    std::cout << "Fcfs " << totalReturnTime << " " << totalWaitTime << " " << totalWaitTime << endl;
    // #################################################
}

int Fcfs::getProcessDur(int numProcess)
{
    return processDur[numProcess];
}
