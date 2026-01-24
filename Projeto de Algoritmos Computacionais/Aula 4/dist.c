/* Distância entre pontos, Guilherme Bruce*/

#include <stdio.h>
#include <math.h>

float descobre_distancia( int qtd)
{
    int i;
    for (i=1; i>=qtd;i++)
    {
        float x1; float x2; float y1; float y2; float resultado;

        printf("Digite um par de pontos seguindo o padrao x1,y1,x2,y2\n");
        scanf("%f %f %f %f", &x1, &y1, &x2, &y2);

        resultado = sqrt( (pow((x1-x2),2) + (pow((y1-y2),2))) );

        printf("A distancia entre esses pares de pontos é %.2f", resultado);

        x1=0; x2=0; y1=0; y2=0;
    }
    return 0;
}



int main ()
{

    int qtd; float x1; float x2; float y1; float y2; int i;

    printf("Insira a quantidade de pares de pontos que você deseja comparar a distancia\n");
    scanf("%d", &qtd);

    if (qtd<=0)
    {
        printf("Erro, a quantidade de pares informados deve ser maior que 0\n");
        return 1;
    }

    return  descobre_distancia(qtd);
}