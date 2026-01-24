#include <stdio.h>
#include <string.h>  
#include <stdlib.h>

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

typedef struct Indice_cep Indice;
struct Indice_cep{
    char cep[8];
    long posicao;
};

int main(int argc, char** argv){
    FILE *f;
    Indice e;
    int inicio = 0, meio, fim;
    int totalRegistros;
    int qt;
    long indice = -1;

    if(argc != 2){
        fprintf(stderr, "USO: %s [CEP]\n", argv[0]);
        return 1;
    }

    f = fopen("Indice.dat", "rb");
    if(!f){
        fprintf(stderr, "O arquivo não foi aberto corretamente\n");
        return 1;
    }

    fseek(f, 0, SEEK_END);
    totalRegistros = ftell(f) / sizeof(Indice);
    rewind(f);

    fim = totalRegistros - 1;

    while(inicio <= fim){
        meio = (inicio + fim) / 2;
        fseek(f, meio * sizeof(Indice), SEEK_SET);
        qt = fread(&e, sizeof(Indice), 1, f);

        if(qt != 1){
            fprintf(stderr, "Erro ao ler o registro\n");
            break;
        }

        int cmp = strncmp(argv[1], e.cep, 8);

        if(cmp == 0){
            printf("Indice: %ld\n", e.posicao);
            indice = e.posicao;
            break;
        }else if(cmp < 0) {
            fim = meio - 1;
        }else{
            inicio = meio + 1;
        }
    }

    if(indice == -1){
        printf("CEP não encontrado.\n");
        return 0;
    }

    FILE *busca_ind;
    Endereco *end;
    end = (Endereco*) malloc(sizeof(Endereco));
    busca_ind = fopen("cep.dat","rb");
    fseek(busca_ind, indice*sizeof(Endereco), SEEK_SET);
    fread(end, sizeof(Endereco),1 ,busca_ind);
    printf("Logradouro: %.72s\n", (*end).logradouro);
    printf("Bairro:     %.72s\n", (*end).bairro);
    printf("Cidade:     %.72s\n", (*end).cidade);
    printf("UF:         %.72s\n", (*end).uf);
    printf("Sigla:      %.2s\n", (*end).sigla);
    printf("CEP:        %.8s\n", (*end).cep);
    fclose(f);
    fclose(busca_ind);
    
    free(end);

    return 0;
}