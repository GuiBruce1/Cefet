/*Cpf, Guilherme Bruce*/

#include <stdio.h>

int main ()
{
    int cpf;
    int aux;
    int soma1 = 0;
    int i;
    int digito;
    int dv1;
    int dv2;
    int soma2 = 0;
    int digito2;
    int aux2;

    printf("Digite o seu cpf sem os digitos verificadores\n");
    scanf("%d", &cpf);

    aux = cpf;

    for ( i=9; i>0; i= i-1) 
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

    for ( i=9; i>0; i= i-1)
    {
        digito2=aux2%10;
        soma2 = soma2 + digito2 * i;
        aux2 = aux2/10;
    }

    dv2 = soma2%11;
    if (dv2 == 10)
    {
        dv2=0;
    }

    printf("O seu prmeiro digito verificador e %d\n", dv1);
    printf("O seu segundo digito verificador e %d\n", dv2);

    return 0;
}