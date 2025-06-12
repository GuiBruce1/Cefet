#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 8

typedef struct _Endereco Endereco;

struct _Endereco{
    char logradouro[72];
    char bairro[72];
    char cidade[72];
    char uf[72];
    char sigla[2];
    char cep[8];
    char lixo[2];
};

int compara(const void *e1, const void *e2){
    return strncmp(((Endereco*)e1)->cep,((Endereco*)e2)->cep,8);
}

int intercala(int *contador, int aux){

    FILE *cep_ordenado = NULL, *a = NULL, *b = NULL;
    Endereco ea, eb;

    char nome_arquivo_a[100];
    char nome_arquivo_b[100];
    char nome_arquivo_saida[100];
    
    sprintf(nome_arquivo_a, "cep%d.dat", *contador);
    a = fopen(nome_arquivo_a, "rb");

    if(!a){
        printf("Erro ao abrir arquivo %s\n", nome_arquivo_a);
        return 0;
    }
    (*contador)++;
    
    sprintf(nome_arquivo_b, "cep%d.dat", *contador);
    b = fopen(nome_arquivo_b, "rb");

    if(!b) {
        printf("Erro ao abrir arquivo %s\n", nome_arquivo_b);
        fclose(a);
        return 0;
    }
    (*contador)++;

    if(aux == (2*N) - 2){
        sprintf(nome_arquivo_saida, "cep_ordenado_final.dat");
    }
    else{
        sprintf(nome_arquivo_saida, "cep%d.dat", aux);
    }
    cep_ordenado = fopen(nome_arquivo_saida, "wb");
    if(!cep_ordenado){
        printf("Erro ao criar arquivo %s\n", nome_arquivo_saida);
        fclose(a);
        fclose(b);
        return 0;
    }
    
    fread(&ea, sizeof(Endereco), 1, a);
    fread(&eb, sizeof(Endereco), 1, b);

    while(!feof(a) && !feof(b)){
        if(compara(&ea, &eb) < 0){
            fwrite(&ea, sizeof(Endereco), 1, cep_ordenado);
            fread(&ea, sizeof(Endereco), 1, a);
        }
        else{
            fwrite(&eb, sizeof(Endereco), 1, cep_ordenado);
            fread(&eb, sizeof(Endereco), 1, b);
        }
    }
    
    while(!feof(a)){
        fwrite(&ea, sizeof(Endereco), 1, cep_ordenado);
        fread(&ea, sizeof(Endereco), 1, a);        
    }
    
    while(!feof(b)){
        fwrite(&eb, sizeof(Endereco), 1, cep_ordenado);
        fread(&eb, sizeof(Endereco), 1, b);        
    }
    
    fclose(a);
    fclose(b);
    fclose(cep_ordenado);
    remove(nome_arquivo_a);
    remove(nome_arquivo_b);
    
    return 1;
}
int main(int argc, char**argv){

    FILE *entrada = NULL, *saida = NULL;
    Endereco *e = NULL;

    long posicao, qtd_enderecos, divisao, qtd_nos, aux = N;
    int i, contador = 0;

    char nome_arquivo[100];
    
    entrada = fopen("cep.dat", "rb");
    if(!entrada){
        fprintf(stderr, "Erro ao abrir arquivo cep.dat\n");
        return 1;
    }
    
    fseek(entrada, 0, SEEK_END);
    posicao = ftell(entrada);
    qtd_enderecos = posicao/sizeof(Endereco);
    divisao = qtd_enderecos/N;
    qtd_nos = (2*N) - 1;
    
    rewind(entrada);

    for(i = 0; i < N; i++){
        e = (Endereco*) malloc(divisao*sizeof(Endereco));
        if(!e){
            fprintf(stderr, "Erro de alocação de memória");
            fclose(entrada);
            return 1;
        }
        
        if(fread(e, sizeof(Endereco), divisao, entrada) == divisao){
            printf("Lido %d = OK\n", i);
        }
        
        qsort(e, divisao, sizeof(Endereco), compara);
        printf("Ordenado %d = OK\n", i);
        
        sprintf(nome_arquivo, "cep%d.dat", i);
        saida = fopen(nome_arquivo, "wb");

        if(!saida){
            printf("Erro ao criar arquivo %s\n", nome_arquivo);
            free(e);
            fclose(entrada);
            return 1;
        }
        
        fwrite(e, sizeof(Endereco), divisao, saida);
        fclose(saida);
        printf("Escrito %d = OK\n", i);
        free(e);
    }

    fclose(entrada);
    
    for(i = 0; i < N-1; i++){
        if(!intercala(&contador, aux)){
            return 1;
        }
        aux++;
    }

    printf("Ordenação feita.");
    
    return 0;
}