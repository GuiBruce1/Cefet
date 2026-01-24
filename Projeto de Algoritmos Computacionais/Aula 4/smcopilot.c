#include <stdio.h>

int main() {
    int quantidade;
    double numero, soma = 0.0;

    // Solicitar a quantidade de números
    printf("Digite a quantidade de números: ");
    scanf("%d", &quantidade);

    // Verificar a validade da quantidade
    if (quantidade <= 0) {
        printf("Quantidade inválida. Insira um número positivo maior que zero.\n");
        return 1; // Encerrar a execução com erro
    }

    // Solicitar os números individuais e calcular a soma
    for (int i = 1; i <= quantidade; i++) {
        printf("Digite o %do número: ", i);
        scanf("%lf", &numero);
        soma += numero;
    }

    // Calcular a média
    double media = soma / quantidade;

    // Exibir o resultado com precisão de duas casas decimais
    printf("A média dos números fornecidos é: %.2lf\n", media);

    return 0; // Encerrar a execução com sucesso
}
