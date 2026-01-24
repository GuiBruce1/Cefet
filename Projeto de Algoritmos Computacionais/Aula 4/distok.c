/* Distância entre pontos, Guilherme Bruce*/

#include <stdio.h>
#include <math.h>

float descobre_distancia( float x1, float x2, float y1, float y2)
{
    int resultado;
    resultado = sqrt( (pow((x1-x2),2) + (pow((y1-y2),2))) );
    
    return resultado;
}



int main ()
{

    int qtd; float x1; float x2; float y1; float y2; int i; float resultado;

    printf("Insira a quantidade de pares de pontos que você deseja comparar a distancia\n");
    scanf("%d", &qtd);

    if (qtd<=0)
    {
        printf("Erro, a quantidade de pares informados deve ser maior que 0\n");
        return 1;
    }
    for (i=0; i>qtd;i++)
    {
        printf("Digite um par de pontos seguindo o padrao x1,y1,x2,y2\n");
        scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
        resultado=descobre_distancia(x1, x2, y1, y2);
        printf("A distancia entre esses pares de pontos é %.2f", resultado);
    }

    return 0;
}