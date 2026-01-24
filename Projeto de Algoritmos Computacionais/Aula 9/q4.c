/*#include <stdio.h>
#include <string.h>

struct Produto{

    char nome[31];
    float preco;
    int qtd; 
};

int le_prod(struct produto p[]){
    int qtd_vendas = 0;

    for(int i = 0; i < 30;i++){

        scanf(" %s", p[i].nome);
        if (strcmp(*p[i].nome[i],"Fim") != 0){
            scanf("%f", &p[i].preco);
            scanf("%d", &p[i].qtd);
            qtd_vendas++;
        } 
        else{
            i = 30; //break disfarçado por Rafael Sancho//
        }
    }
    return qtd_vendas;
}

void guarda_nomes(struct produto p[], char nomes[][31], int qtd_vendas){

    for(int i = 0; i < qtd_vendas;i++){
        strcpy(nomes[i],p[i].nome);
    }

}

void pesquisa(struct Produto p[],char nomes[][31], int qtd_vendas){
    char pesquisa[31];
    scanf(" %s", pesquisa);

    for(int i = 0; i < qtd_vendas; i++){
        if(strcmp(p.[i]nome,pesquisa) == 0){
            printf("O preço deste produto é: %.2f", p[i].preco);
            printf("A quantidade em estoque é: %d", p[i].qtd);
            return;
        }
    }
    printf("Produto inexistente!");
}

int main(void){
    struct Produto p[30];

    int qtd_vendas = le_prod(p);
    char nomes[][31];
    guarda_nomes(p,nomes[][30], qtd_vendas);


    return 0;
}*/

///////////////////
#include <stdio.h>
#include <string.h>

struct Produto {
    char nome[31];
    float preco;
    int qtd;
};

int le_prod(struct Produto p[]) {
    int qtd_vendas = 0;

    for (int i = 0; i < 30 && qtd_vendas < 30; i++) {
        scanf("%30[^\n]", p[i].nome); // Limita o tamanho da entrada para evitar buffer overflow
        if (strcmp(p[i].nome, "Fim") == 0) {
            break;
        }
        scanf("%f", &p[i].preco);
        scanf("%d", &p[i].qtd);
        qtd_vendas++;
    }

    return qtd_vendas;
}

void guarda_nomes(struct Produto p[], char nomes[][31], int qtd_vendas) {
    for (int i = 0; i < qtd_vendas; i++) {
        strcpy(nomes[i], p[i].nome);
    }
}

void pesquisa(struct Produto p[], char nomes[][31], int qtd_vendas) {
    char pesquisa[31];
    do{for (int i = 0; i < qtd_vendas; i++) { //sei que tá esquisito
            scanf(" %30s", pesquisa);
            if (strcmp(p[i].nome, pesquisa) == 0) {
                printf("O preço deste produto é: %.2f\n", p[i].preco);
                printf("A quantidade em estoque é: %d\n", p[i].qtd);
            }else{
                printf("Produto inexistente!");
            }
        }}while(strcmp(pesquisa,"Fim") != 0)
}

int main() {
    struct Produto p[30];
    int qtd_vendas = le_prod(p);
    char nomes[qtd_vendas][31];

    guarda_nomes(p, nomes, qtd_vendas);
    pesquisa(p, nomes, qtd_vendas);

    return 0;
}