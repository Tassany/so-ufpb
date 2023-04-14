// Neste projeto você deve implementar um conjunto
// de algoritmos de escalonamento de CPU e escrever
// um programa que calcula uma série de estatísticas
// baseado nestes algoritmos.
// ¨ Os algoritmos de escalonamento a serem
// implementados são os seguintes :
// ¤ FCFS : First -
//     Come,
//     First - Served
// ¤ SJF : Shortest Job First
// ¤ RR : Round Robin(com quantum = 2)

// ¨ O seu programa deverá ler de um arquivo uma
// lista de processos com seus respectivos tempos de
// chegada e de duração e deverá imprimir na tela
// uma tabela contendo os valores para as seguintes
// métricas :
// ¤ Tempo de retorno médio
// ¤ Tempo de resposta médio
// ¤ Tempo de espera médio
#ifndef _FCFS_H_
#define _FCFS_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

class Fcfs
{

public:
    Fcfs();
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