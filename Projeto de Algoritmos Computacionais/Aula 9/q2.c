#include <stdio.h>
#include <string.h>


void analise(char qtd_vendas[][], char precos[][]){

    float totalComb = 0;
    float totalDia = 0;
    float totais[4];
    float total_cada_dia[31];
    float aux = 0;

    for(int i = 0; i < 4; i++){

        for(int j = 0; j < 31; j++){

            totalComb = totalComb + (qtd_vendas[i][j] * precos[i][j]);

            totais[j] = totalComb;
        }

    }

    for(int i = 0; i < 31; i++){

            
        totalDia = totalDia + (qtd_vendas[0][i] * precos[0][i]) + (qtd_vendas[1][i] * precos[1][i]) + (qtd_vendas[2][i] * precos[2][i]) + (qtd_vendas[3][i] * precos[3][i]);

        total_cada_dia[j] = totalDia;
        
    }




    printf("Valor total de vendas do combustível 1: %.2f\n", totais[0]);
    printf("Valor total de vendas do combustível 2: %.2f\n", totais[1]);
    printf("Valor total de vendas do combustível 3: %.2f\n", totais[2]);
    printf("Valor total de vendas do combustível 4: %.2f\n", totais[3]);

}

int main(){

    char qtd_vendas[4][31];
    char precos[4][31];

    analise(&qtd_vendas, &precos);

    return 0;
}
