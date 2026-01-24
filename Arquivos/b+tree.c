#include <stdio.h>

#define n 5

struct _NoIntermediario
{
    int qtd;
    tchave chaves[n]; // 8 bytes
    tpont filhos[n+1]; // 4 bytes
}
struct _NoFolha
{
    int qtd;
    tchave chaves[n]; // 8 bytes
    tpont dados[n]; // 4 bytes
    tpont prox;
}
/*
    |   H   |     N     |    P    |
    |   1   |    300    |   301   |
    |   2   |  300*301  |  301^2  |
    |   3   | 301^2*300 |  301^3  |
*/
//A maior parte dos nós são folhas. Como folhas não tem nós filhos, a maior parte dos registros são nulos.