#include <stdio.h>

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
int compara(const void *e1, const void *e2){
	return strncmp(((Indice*)e1)->cep,((Indice*)e2)->cep,8);
}

int main(int argc, char** argv){

    FILE *entrada, *saida;
	Endereco e;
    Indice *ind;
    int cabeca;
	int tam;
    int qtdRegistro;
	
    entrada = fopen("cep.dat","rb");
    if(!entrada){
        fprintf(stderr, "O arquivo não foi aberto corretamente");
        return 1;
    }

	fseek(entrada,0,SEEK_END);
    tam = ftell(entrada);
    qtdRegistro = tam/sizeof(Endereco);
    //fim = tamReg-1;
    rewind(entrada);
    ind = (Indice*) malloc(qtdRegistro*sizeof(Indice));

    for(int i = 0; i < qtdRegistro; i++){
        fread(&e,sizeof(Endereco),1,entrada);
        strncpy(ind[i].cep,e.cep,8);
        ind[i].posicao = i;
    }
    qsort(ind,qtdRegistro,sizeof(Indice),compara);
	printf("Ordenado = OK\n");
	saida = fopen("Indice.dat","wb");
	fwrite(ind,sizeof(Indice),qtdRegistro,saida);
    fclose(entrada);
	fclose(saida);
	free(e);
    free(ind);
    return 0;
}