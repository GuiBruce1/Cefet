#include <stdio.h>
//ftell() retorna a posição atual no arquivo
//fseek(nome do arquivo,0,SEEK_END) vai para a ultima posição do arquivo, a prox sera o EOF, então para sabermos quantos registros temos é só fazer fseek(f,0,SEEK_END) depois ftell para me dizer a posição que é o tamanho e dividir por sizeof(dados)
//fseek(nome do arquivo,0,SEEK_SET) volta pro inicio, rewind(nome do arquivo) faz a mesma coisa
int main(int argc, char** argv){

    FILE *entrada;
	char c;
    int contador = 1;
    int qt[256] = {0};

    if(argc != 2){
		fprintf(stderr,"Erro na chamada do comando.\n");
		fprintf(stderr,"Uso: %s [ARQUIVO A SER LIDO].\n", argv[0]);
		return 1;
	}
	
    entrada = fopen(argv[1],"rb");
    if(!entrada){
        fprintf(stderr, "O arquivo não foi aberto corretamente");
        return 1;
    }
    
    c = fgetc(entrada);
    while(!feof(entrada)){
        if(c == '\n'){
            contador++;
        }
        qt[c]++;
        c = fgetc(entrada);
    }
    
    fclose(entrada);
    printf("O arquivo tem %d linhas\n", contador);
    for(int i = 0; i < 256;i++){
        if(qt[i] != 0){
            printf("O caractere %d tem %d ocorrência(s)\n", i, qt[i]);
        }
    }
    
    return 0;
}