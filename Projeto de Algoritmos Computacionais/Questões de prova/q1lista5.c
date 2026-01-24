#include <stdio.h>

float processa_Downloads (int qtdDownloads, float precoMbyte)
{
    float tamanhoMbyte; float valor_a_pagar; float total_a_pagar=0; int contador; float todo;
    for ( int i = 0; i < qtdDownloads; i++)
    {
        printf("Insira o tamanho de Mbytes desse arquivo na forma de um numero inteiro\n");
        scanf("%f", &tamanhoMbyte);
        valor_a_pagar = precoMbyte * tamanhoMbyte;
        total_a_pagar = total_a_pagar + valor_a_pagar;
    }
    printf("O total a ser pago por esse usario e %.2f\n", total_a_pagar);
    return total_a_pagar;
}


int main ()
{
    float precoMbyte; int qtdDownloads; float tamanhoMbyte; float media=0; int contador=0; float todo=0; float total_a_pagar=0;

    printf("Insira o preco fixo de MBytes do site\n");
    scanf("%f", &precoMbyte);
    printf("Insira a quantidade de dowloads desejada\n");
    scanf("%d", &qtdDownloads);

    if (qtdDownloads==0) // posso tratar o erro, mas não ta pedindo na questão//
    {
        printf("Nenhum valor sera calculado sem um usuario");
        return 1;
    }
    
    

    while(qtdDownloads!=0)
    {
        total_a_pagar = processa_Downloads ( qtdDownloads, precoMbyte);
        contador++;
        todo +=total_a_pagar;
        printf("%.2f\n", todo);
        printf("Ola novo usario! Insira sua quantidade de Dowloads\n");
        scanf("%d", &qtdDownloads);
        if (qtdDownloads!=0) // perguntar se esse if é redundante//
        {
            continue;
        }
    }
    media = todo/contador;
    printf("A media dos precos pagos pelos usuarios e %.2f", media);
    return 0;
}