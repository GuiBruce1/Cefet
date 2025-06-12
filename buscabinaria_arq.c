#include <stdio.h>
#include <string.h>

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
int main(int argc, char** argv){

    FILE *f;
	Endereco e;
	int qt;
	int tam;
    int inicio = 0;
    int fim;
    int meio;
    int tamReg;
    
    if(argc != 2){
		fprintf(stderr, "USO: %s [CEP]", argv[0]);
		return 1;
	}
    

    f = fopen("cep_ordenado.dat","rb");
    if(!f){
        fprintf(stderr, "O arquivo não foi aberto corretamente");
        return 1;
    }
    
    fseek(f,0,SEEK_END);
    tam = ftell(f);
    tamReg = tam/sizeof(Endereco);
    fim = tamReg-1;
    rewind(f);

    //qt = fread(&e,sizeof(Endereco),1,f);

    while(inicio <= tamReg-1){
        meio = (inicio + fim)/2;
        fseek(f,meio * sizeof(Endereco),SEEK_SET);
        qt = fread(&e,sizeof(Endereco),1,f);
        
        if(strncmp(argv[1],e.cep,8)==0){
			printf("%.72s\n%.72s\n%.72s\n%.72s\n%.2s\n%.8s\n",e.logradouro,e.bairro,e.cidade,e.uf,e.sigla,e.cep);
			break;
		}else if(strncmp(argv[1],e.cep, 8) < 0){
            fim = meio - 1;
        }else if(strncmp(argv[1],e.cep, 8) > 0){
            inicio = meio + 1;
        }

    }

}