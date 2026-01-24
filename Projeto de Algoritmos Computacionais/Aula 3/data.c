/*Datas válidas, Guilherme Bruce*/
#include <stdio.h>

int ano_Bissexto (int ano)
{
     return (ano%4==0 && (ano%100!=0 || ano%400==0)); 
     }

    int main()
{
    int dia, mes, ano;
    printf("Insira sua data e verificaremos se ela e valida ");
    scanf("%d %d %d", &dia, &mes, &ano);

    if (mes==2) {
        if(ano_Bissexto(ano) && dia>=1 && dia<=29)
        {
            printf("sua data e valida");
        }   
        else {   
            if (dia>=1 && dia<=28)
            {
                printf("Sua data e valida");
            }
        
            else {
                printf("Sua data e invalida");
            }
        }
    }
    if ( mes==4 || mes==6 || mes==9 || mes==11) {
        if (dia>=1 && dia<=30)
        {
            printf("Sua data e valida");
        }
        else {
            printf("Sua data e invalida");
        }
    }
        
    if  ( mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) {
        if (dia>=1 && dia<=31) 
        {
            printf("Sua data e valida");
        }
        else {
            printf("Sua data é invalida");
        }
    }
    return 0;
}