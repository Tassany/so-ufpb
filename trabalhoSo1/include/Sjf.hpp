#ifndef _SJF_H_
#define _SJF_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

class Sjf
{

public:
    Sjf();
    // Coloca en prioridde de execução quem possuir o menor tempo de processamento
    // com ou sem preempção???????????????

    vector<int> returnTime; // quantidade necessaria de tempo para executar um processo
    // tempo de retorno = tempo que entrou - tempo de chegada

    vector<int> responseTime; // quantidade de tempo entre a requisicao de execucao de um
    // programa e a producao da primeira resposta
    // tempo de resposta = tempo que entrou pela 1 vez - tempo de chegada

    vector<int> waitTime; // quantidade de tempo que o processo aguardou na fila de prontos
    // tempo de espera = acumulado do tempo esperando (ou primeira vez que entrou) - tempo de chegada

    int getArrive(int numProcess);
    int getProcessDur(int numProcess);
    void readData();
    int numProcess; // quantidade total de processos

    vector<int> arrive;     // tempo que o processo chegou na fila de prontos
    vector<int> processDur; // tempo que ele executa o processo até seu término
};

#endif