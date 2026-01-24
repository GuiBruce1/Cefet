/*Soma e média dos números, Guilherme Bruce*/

#include <stdio.h>

int main()
{
    float soma=0;
    float media;
    int i;
    float valor;

    printf("Insira a quantidade de numeros que irao ser incluidos na media\n");
    scanf("%d", &i);

    if (i<=0)
    {
        printf("Erro, a quantidade de numeros incluidos na media nao pode ser 0 ou menor que 0");
        return 1;
    }

    for ( int help=1; help <= i; help++)
    {
        printf("insira o %do valor\n", help);
        scanf("%f", &valor);
        soma = soma + valor;
    }
    
    media = soma/i;

    printf("Sua media e %.2f", media);

    return 0;
}