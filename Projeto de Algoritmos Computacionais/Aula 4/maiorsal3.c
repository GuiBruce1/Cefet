/*Maior salário, Guilherme Bruce*/
#include <stdio.h>


int maior_Salario(int salario, int i)
{   
    int maior, contador, resultado;

    if (i==0)
    {
      maior = salario;
      contador = 1;
    } 
    else if (salario > maior)
    {
      maior = salario;
      contador = 1;
    } 
    else if (salario==maior)
    {
      contador++;
    }
    resultado = maior*10+contador;

    return resultado;
}


int main ()
{
    int qtd, salario, resultado, contador;

    printf("Insira a quantidade de funcionarios que deseja comparar os salarios\n");
    scanf("%d", &qtd);
    for (int i=0; i<qtd; i++)
    {
        printf("Insira o %do salario\n", i+1);
        scanf("%d", &salario);
        printf("Insira a matrícula do %do funcionario\n", i+1);

        resultado = maior_Salario(salario, i)/10;
        contador = maior_Salario(salario, i)%10;
    }

    printf("O maior salario e %d\n", resultado);
    printf("O numero de funcionarios que possuem esse salario e %d", resultado);
}