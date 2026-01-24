/*Maior salário, Guilherme Bruce*/
#include <stdio.h>


int maior_Salario(int qtd)
{   
    int maior, salario, contador=0, resultado, matricula;

    for (int i=0; i<qtd; i++ )
    {
        printf("Insira o salario do %do funcionario\n", i+1);
        scanf("%d", &salario);
        printf("Insira a matricula do %do funcionario\n", i+1);
        scanf("%d", &matricula);
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
    }

    resultado = maior;
    
    printf("O maior salario e %d\n", resultado);
    printf("O numero de funcionarios que possuem esse salario e %d\n", contador);

}


int main ()
{
    int qtd, maior, salario, contador, resultado;

    printf("Insira a quantidade de funcionarios que deseja comparar os salarios\n");
    scanf("%d", &qtd);

    maior_Salario(qtd);

    return 0;
}