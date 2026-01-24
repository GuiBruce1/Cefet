#include <stdio.h>

float calcula_preco(int qtdperifericos)
{
        float preco_Periferico; float total_perifericos=0; float valor_a_pagar=0; float preco_basico;
    for (int i = 0; i < qtdperifericos; i++)
    {
        printf("Insira o preco do periferico\n");
        scanf("%f", &preco_Periferico );
        valor_a_pagar = preco_Periferico;
        total_perifericos += valor_a_pagar;
    }

    return total_perifericos;

}

int main()
{
    float preco_basico; float total; float total_dosperifericos; int qtdperifericos; int codigo; int contador_perifericos=0; int contador_semperifericos=0; float media; float todo=0;

    printf("Ola! Insira o codigo do modelo basico escolhido\n");
    scanf("%d", &codigo);

    if (codigo == 0)
    {
        printf("Nenhuma venda foi registrada. Ate mais!");
        return 1;
    }

    while(codigo != 0)
    {
    printf("Insira o preco do modelo basico escolhido\n");
    scanf("%f", &preco_basico);
    printf("Insira a quantidade de perifericos que deseja\n");
    scanf("%d", &qtdperifericos);
    if (qtdperifericos == 0)
    {
        total = preco_basico;
        contador_semperifericos++;
    }
    else
    {
        total_dosperifericos = calcula_preco(qtdperifericos);
        total = preco_basico + total_dosperifericos;
        contador_perifericos++;
    }
    todo+=total;
    printf("O valor da venda foi %.2f\n", total);
    printf("Insira o codigo do novo modelo basico escolhido\n");
    scanf("%d", &codigo);
    }

    media = todo / (contador_perifericos + contador_semperifericos);
    printf("A quantidade de vendas sem perifericos adicionais foi %d\n", contador_semperifericos);
    printf("O valor medio de todas as vendas foi %.2f", media);

    return 0;
}