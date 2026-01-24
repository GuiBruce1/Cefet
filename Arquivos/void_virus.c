#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void intercala(int *aux,int *contador){
	
	FILE* cep_ordenado, *a, *b;
	Endereco ea, eb;

	char nome_arquivo[100];
    char nome_arquivo2[100];
    char nome_arquivo_saida[100];


	sprintf(nome_arquivo, "cep%d.dat", *contador);
	a = fopen(nome_arquivo, "rb");
	(*contador)++;
    
	sprintf(nome_arquivo2, "cep%d.dat", *contador);
	b = fopen(nome_arquivo2, "rb");
	(*contador)++;

    sprintf(nome_arquivo_saida, "cep%d.dat", *aux);
    (*aux)--;
    cep_ordenado = fopen(nome_arquivo_saida, "wb");

	fread(&ea,sizeof(Endereco),1,a);
	fread(&eb,sizeof(Endereco),1,b);



	while(!feof(a) && !feof(b))
	{
		if(compara(&ea,&eb)<0)
		{
			fwrite(&ea,sizeof(Endereco),1,cep_ordenado);
			fread(&ea,sizeof(Endereco),1,a);
		}
		else
		{
			fwrite(&eb,sizeof(Endereco),1,cep_ordenado);
			fread(&eb,sizeof(Endereco),1,b);
		}
	}

	while(!feof(a))
	{
		fwrite(&ea,sizeof(Endereco),1,cep_ordenado);
		fread(&ea,sizeof(Endereco),1,a);		
	}
	
	while(!feof(b))
	{
		fwrite(&eb,sizeof(Endereco),1,cep_ordenado);
		fread(&eb,sizeof(Endereco),1,b);		
	}

	fclose(a);
	fclose(b);
	fclose(cep_ordenado);
	remove(nome_arquivo);
    remove(nome_arquivo2); 
}

int main(int argc, char**argv){
	FILE *f, *saida;
	Endereco *e;
	long posicao, qtd, divisao;
	int i, n;
	char nome_arquivo[100];
    int contador = 0;

	f = fopen("cep.dat", "rb");
	fseek(f, 0, SEEK_END);
	posicao = ftell(f);
	qtd = posicao/sizeof(Endereco);
	divisao = qtd/N;
    rewind(f);
	for(i = 0; i < N; i++){
        e = (Endereco*) malloc(divisao*sizeof(Endereco));
		if(fread(e, sizeof(Endereco), divisao, f) == divisao)
		{
			printf("Lido %d = OK\n", i);
		}
		qsort(e, divisao,sizeof(Endereco), compara);
		printf("Ordenado %d = OK\n", i);
		sprintf(nome_arquivo, "cep%d.dat", i);
		saida = fopen(nome_arquivo, "wb");
		fwrite(e, sizeof(Endereco), divisao, saida);
		fclose(saida);
		printf("Escrito %d = OK\n", i);
		free(e);
	}
    int qtd_nos = (2*N)-1;
    int aux = qtd_nos;
    for(int i = 0; i < qtd_nos -1; i++){
        intercala(&aux, &contador);
    }
    

}