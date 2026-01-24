#include <stdio.h>


int main(){
    int n;
    int soma = 0;
    int i;

    printf("Insira o valor N e exibiremos a soma de 1 até o valor N\n");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Erro, o número inserido deve ser maior que 0\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        soma = soma + i+1;
    }

    printf("A soma dos números até %d é %d", n, soma);

    return 0;
}