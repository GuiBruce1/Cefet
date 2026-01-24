#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER 2048 
#define HASH_SIZE 29      

struct DadosNascimento{
    int index;
    int CODMUNRES; 
    char data_nasc[11];
    int PESO;           
    int SEMAGESTAC;
    float adeq_peso_id_gestac;
    int SEXO;
    int IDANOMAL;
    int RACACOR;
    int ESCMAEAGR1;
    int ESTCIVMAE;
    int IDADEMAE;
    int CONSULTAS;
    int PARTO;
    int STTRABPART;
    int KOTELCHUCK;
    int APGAR5;
    int TPROBSON;
};

typedef struct No{
    int uf_ibge;          
    double soma_pesos;  
    int quantidade;
    struct No* prox;
} No;

int funcaoHash(int chave){
    return chave % HASH_SIZE;
}

void inicializarTabela(No tabela[]) {
    for (int i = 0; i < HASH_SIZE; i++) {
        tabela[i].uf_ibge = -1; 
        tabela[i].soma_pesos = 0;
        tabela[i].quantidade = 0;
        tabela[i].prox = NULL;
    }
}

void inserir(No tabela[], int uf_ibge, float peso){
    int indice = funcaoHash(uf_ibge);
    No* cabeca = &tabela[indice];

    if(peso <= 0){
        return;
    }

    if(cabeca->uf_ibge == -1){
        cabeca->uf_ibge = uf_ibge;
        cabeca->soma_pesos = peso;
        cabeca->quantidade = 1;
        return;
    }

    No* atual = cabeca;
    while(atual != NULL){
        if(atual->uf_ibge == uf_ibge){
            atual->soma_pesos += peso;
            atual->quantidade += 1;
            return;
        }
        if(atual->prox == NULL){
            break;
        }
        atual = atual->prox;
    }

    No* novo = (No*) malloc(sizeof(No));
    if(novo == NULL){
        fprintf(stderr, "Erro de alocação de memória!\n");
        return;
    }

    novo->uf_ibge = uf_ibge;
    novo->soma_pesos = peso;
    novo->quantidade = 1;
    novo->prox = NULL;
    
    atual->prox = novo;
}

void imprimirMedias(No tabela[]){
    printf("================================\n");
    printf("%2s | %8s  | %10s|\n", "UF", "Nascimentos", "Média peso");
    printf("---|--------------|------------|\n");

    for (int i = 0; i < HASH_SIZE; i++) {
        No* atual = &tabela[i];
        if (atual->uf_ibge == -1) continue; 

        while (atual != NULL) {
            double media = atual->soma_pesos / atual->quantidade;
            printf("%2d | %12d | %7.2f Kg |\n", 
                   atual->uf_ibge, 
                   atual->quantidade, 
                   media / 1000);
            atual = atual->prox;
        }
    }
    printf("================================\n");

}

void liberarTabela(No tabela[]) {
    for (int i = 0; i < HASH_SIZE; i++) {
        No* atual = tabela[i].prox;
        while (atual != NULL) {
            No* temp = atual;
            atual = atual->prox;
            free(temp);
        }
        
        tabela[i].prox = NULL;
    }
}

int main() {
    No tabela[HASH_SIZE];
    inicializarTabela(tabela);

    FILE *f = fopen("sinasc.csv", "r");
    if(f == NULL){
        perror("Erro ao abrir o arquivo sinasc.csv");
        return 1;
    }

    char buffer[MAX_BUFFER];
    char *prox_token = NULL;
    char* campo[18];
    struct DadosNascimento dn;

    fgets(buffer, MAX_BUFFER, f);
    while(fgets(buffer, MAX_BUFFER, f)){
        campo[0] = strtok_r(buffer, ",\n", &prox_token);
        for(int i = 1; i < 18; i++){
            campo[i] = strtok_r(NULL, ",\n", &prox_token);
            if(campo[i] == NULL){
                campo[i] = "";
            }
        }

        dn.CODMUNRES = atoi(campo[1]);
        dn.PESO = atoi(campo[3]);

        if(dn.CODMUNRES > 0 && dn.PESO > 0){
            int uf_ibge = dn.CODMUNRES / 10000;
            inserir(tabela, uf_ibge, (float)dn.PESO);
        }
    }

    fclose(f);
    imprimirMedias(tabela);
    liberarTabela(tabela);

    return 0;
}