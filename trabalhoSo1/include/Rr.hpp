#ifndef _RR_H_
#define _RR_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

class Rr
{

public:
    Rr();
    // Primeiro a entrar, primeiro a ser atendido

    vector<int> returnTime; // quantidade necessaria de tempo para executar um processo
    // tempo de retorno = tempo que entrou - tempo de chegada

    vector<int> responseTime; // quantidade de tempo entre a requisicao de execucao de um
    // programa e a producao da primeira resposta
    // tempo de resposta = tempo que entrou pela 1 vez - tempo de chegada

    vector<int> waitTime; // quantidade de tempo que o processo aguardou na fila de prontos
    // tempo de espera = tempo de espera do anterior + duração do processor
    // caso seja o primeiro a entrar, o tempo de espera é 0

    int getArrive(int numProcess);
    int getProcessDur(int numProcess);
    void readData();
    int numProcess; // quantidade total de processos

    vector<int> arrive;     // tempo que o processo chegou na fila de prontos
    vector<int> processDur; // tempo que ele executa o processo até seu término
};

#endif