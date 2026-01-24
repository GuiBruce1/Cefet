#include <stdio.h>
#include <stdbool.h>

// Uma função que verifica se um ano é bissexto
bool eh_bissexto(int ano) {
  if (ano % 4 == 0) {
    if (ano % 100 == 0) {
      if (ano % 400 == 0) {
        return true; // Divisível por 4, 100 e 400
      } else {
        return false; // Divisível por 4 e 100, mas não por 400
      }
    } else {
      return true; // Divisível por 4, mas não por 100
    }
  } else {
    return false; // Não divisível por 4
  }
}

// Uma função que verifica se uma data é válida
bool eh_valida(int dia, int mes, int ano) {
  // Verifica se os valores estão dentro dos limites
  if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1) {
    return false;
  }

  // Verifica se o mês tem 30 ou 31 dias
  if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
    if (dia > 30) {
      return false;
    }
  }

  // Verifica se o mês é fevereiro e se o ano é bissexto
  if (mes == 2) {
    if (eh_bissexto(ano)) {
      if (dia > 29) {
        return false;
      }
    } else {
      if (dia > 28) {
        return false;
      }
    }
  }

  // Se passou por todas as verificações, a data é válida
  return true;
}

// Um programa que testa a função eh_valida
int main() {
  int dia, mes, ano;
  printf("Digite uma data no formato dd/mm/aaaa: ");
  scanf("%d/%d/%d", &dia, &mes, &ano);

  if (eh_valida(dia, mes, ano)) {
    printf("A data %d/%d/%d é válida.\n", dia, mes, ano);
  } else {
    printf("A data %d/%d/%d é inválida.\n", dia, mes, ano);
  }

  return 0;
}
