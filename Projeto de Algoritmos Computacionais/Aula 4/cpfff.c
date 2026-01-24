/*Cpf, Guilherme Bruce*/

#include <stdio.h>

int calcula_Dvs (int cpf) 
{
    int soma1 = 0; int digito; int aux=cpf; int dv1;  int soma2 = 0; int digito2; int aux2; int dv2; aux2 = cpf*10+dv1; int dvs;
    
    aux = cpf;

    for (int i=9; i>0; i= i-1) 
    {
        digito = aux%10;
        soma1 = soma1 + digito * i;
        aux = aux/10;
    }

    dv1 = soma1%11;

    if (dv1 == 10)
    {
        dv1 = 0;
    }

    aux2 = cpf*10+dv1;

    for (int i=9; i>0; i= i-1)
    {
        digito2=aux2%10;
        soma2 = soma2 + digito2 * i;
        aux2 = aux2/10;
    }

    dv2 = soma2%11;

    dvs= dv1*10+dv2;

        return dvs;
}

int main ()
{
    int cpf;
    int aux;
    int soma1 = 0;
    int digito;
    int dv1;
    int dv2;
    int soma2 = 0;
    int digito2;
    int aux2;
    int dvs;

    printf("Digite o seu cpf sem os digitos verificadores\n");
    scanf("%d", &cpf);

    dvs = calcula_Dvs(cpf);

    printf("Os seus digitos verificadores sao %d\n", dvs);

    return 0;
}