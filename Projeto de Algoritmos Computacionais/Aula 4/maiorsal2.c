/*Maior salário, Guilherme Bruce*/
#include <stdio.h>


int maior_Salario(int qtd)
{   
    int maior, salario, contador, resultado, i;

    if (i==0)
    {
        maior = salario;
        contador = 1;
    } else
      {
        if (salario > maior)
        {
            maior = salario;
            contador = 1;
        } else
          {
            if (salario==maior)
            {
                contador++;
            }
          }
      }

    resultado = maior*10+contador;

    return resultado;
}


int main ()
{
    int qtd, maior, salario, contador, resultado;

    printf("Insira a quantidade de funcionarios que deseja comparar os salarios\n");
    scanf("%d", &qtd);
    for (int i=0; i<qtd; i++)
    {
        printf("Insira o %do salario\n", i+1);
        scanf("%d", &salario);

        resultado = maior_Salario(qtd);
    }

    printf("O maior salario e %d\n", resultado/10);
    printf("O numero de funcionarios que possuem esse salario e %d", resultado%10);
}