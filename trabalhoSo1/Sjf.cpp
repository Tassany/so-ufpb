#include "./include/Sjf.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

Sjf::Sjf()
{
    numProcess = 0;
}

int Sjf::getArrive(int numProcess)
{
    return arrive[numProcess];
}

void Sjf::readData()
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
    vector<int> newArrive;

    // lendo o arquivo de instancias
    while (!input.eof())
    {
        input >> i;
        arrive.push_back(i);
        input >> i;
        processDur.push_back(i);
        numProcess++;
    }

    // ############### Ordenação ###################
    minProcessDur = processDur[0];
    newDur.push_back(0);
    newArrive.push_back(0);

    while (numProcess)
    {
        minProcessDur = processDur[0];
        for (i = 0; i < numProcess; i++)
        {

            if (arrive[i] <= currentTime)
            {
                if (processDur[i] < minProcessDur)
                {
                    minProcessDur = processDur[i];

                    currentIndex = i;

                    currentTime = currentTime + minProcessDur;

                    newDur.push_back(currentTime);
                    newArrive.push_back(arrive[i]);

                    processDur.erase(processDur.begin() + currentIndex);
                    arrive.erase(arrive.begin() + currentIndex);

                    i--;
                    numProcess--;
                }
            }
        }

        if (numProcess == 1)
        {
            minProcessDur = processDur[0];

            currentIndex = 0;

            currentTime = currentTime + minProcessDur;

            newDur.push_back(currentTime);
            newArrive.push_back(arrive[currentIndex]);

            processDur.erase(processDur.begin() + currentIndex);
            arrive.erase(arrive.begin() + currentIndex);

            numProcess--;
        }
    }

    // #################################################

    // ############### Tempo de espera ###################
    numProcess = newDur.size();
    for (int i = 0; i < numProcess - 1; i++)
    {
        waitTime.push_back(newDur[i]);
    }

    for (i = 0; i < numProcess - 1; i++)
    {
        totalWaitTime = totalWaitTime + waitTime[i];
    }

    for (i = 0; i < numProcess - 1; i++)
    {
        totalArriveTime = totalArriveTime + newArrive[i];
    }

    totalWaitTime = totalWaitTime - totalArriveTime;

    totalWaitTime = (totalWaitTime) / (numProcess - 1);

    // #################################################

    // ############### Tempo de retorno ###################

    for (int i = 0; i < numProcess; i++)
    {
        totalReturnTime = totalReturnTime + newDur[i];
    }

    totalReturnTime = totalReturnTime - totalArriveTime;

    totalReturnTime = totalReturnTime / (numProcess - 1);

    // ####################################################
    // ############### Tempo de resposta ###################

    // Por não ter preempção o tempo de resposta é o mesmo que o tempo de espera

    std::cout << "Sjt " << totalReturnTime << " " << totalWaitTime << " " << totalWaitTime << endl;
    // #################################################
}

int Sjf::getProcessDur(int numProcess)
{
    return processDur[numProcess];
}
