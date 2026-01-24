#include <stdio.h>

    int ano_Bissexto (int ano)
    {
     return (ano%4==0 && (ano%100!=0 || ano%400==0)); 
    }

    void data_Valida (int data)
    {
        int dia, mes, ano;

        dia = data/1000000;
        mes = (data/10000) % 100;
        ano = data % 10000;

    if (mes==2) {
        if(ano_Bissexto(ano) && dia>=1 && dia<=29)
        {
            printf("sua data e valida");
        }   
        else {   
            if (dia>=1 && dia<=28)
            {
                printf("Sua data %d e valida");
            }
        
            else {
                printf("Sua data %d e invalida");
            }
        }
    }
    if ( mes==4 || mes==6 || mes==9 || mes==11) {
        if (dia>=1 && dia<=30)
        {
            printf("Sua data %d e valida");
        }
        else {
            printf("Sua data %d e invalida");
        }
    }
        
    if  ( mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) {
        if (dia>=1 && dia<=31) 
        {
            printf("Sua data %d e valida");
        }
        else {
            printf("Sua data %d é invalida");
        }
    }
    }


    int main()
{
    int data;
    data = 1; /*Defini a data como 1 para entrar no loop do while*/

    while ( data!=-1)
    {
        printf("\nInsira sua data no formato DDMMAAAA e verificaremos se ela e valida\n ");
        scanf("%d", &data);
        data_Valida (data);
    }
    return 0;
}