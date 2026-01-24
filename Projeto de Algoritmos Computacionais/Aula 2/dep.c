/*Deputados, Guilherme Bruce*/

#include <stdio.h>

int main()
{

int populacao, deputadosFederais;

    printf("Insira a população total de seu estado e te mostraremos quantos deputados federais ele possui ");
    scanf("%d", &populacao);

    deputadosFederais=(populacao*513.0)/(190755799);

    if (deputadosFederais > 8 && deputadosFederais < 70)
    {
        printf("Seu estado possui %d deputados federais", deputadosFederais);
    }
    else 
    {   if (deputadosFederais >= 70) {

            printf("O seu estado possui 70 deputados federais");}

        else{
            if (deputadosFederais <= 8) {

                printf("O seu estado tem 8 deputados federais");}
            }
    }
    return 0;

    }










