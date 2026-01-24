#include <stdio.h>

int main()
{
    float totalNormal = 0;
    int qtdNormal = 0;
    int qtdSuspeitas = 0;
    float transacao;
    scanf("%f", &transacao);
    printf("%f normal\n", transacao);
    totalNormal += transacao;
    qtdNormal++;
    while (1) {
        scanf("%f", &transacao);
        if(transacao > 1.5*totalNormal/qtdNormal){
            printf("%f normal\n", transacao);
            totalNormal += transacao;
            qtdNormal++;
        } 
        else if (transacao < 2.0*totalNormal/qtdNormal){
            printf(" %f suspeita\n", transacao);
            qtdSuspeitas++;
        }
        else {
            printf("%f bloqueada\n", transacao);
            break;
        }
    }
    printf("Media transacoes normais: %f\n", totalNormal/qtdNormal);
    printf("Transacoes normais: %d\n\n", qtdNormal);
    printf("Quantidade de transacoes suspeitas: %f\n", qtdSuspeitas);
    return 0;
}