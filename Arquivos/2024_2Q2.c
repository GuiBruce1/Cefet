#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv){

    int balanceado = 1;
    int verificacao = 0;
    char c;
    FILE *entrada;
	
    entrada = fopen(argv[1],"rb");
    if(!entrada){
        fprintf(stderr, "O arquivo não foi aberto corretamente");
        return 1;
    }

    while((c = fgetc(entrada)) != EOF){
        if(c == '{'){
            verificacao++;
        }
        if(c == '}'){
            verificacao--;
        }
        if(verificacao < 0){
            balanceado = 0;
        }
    }
    if(verificacao != 0 || balanceado == 0){
        printf("Está desbalanceado");
    }else{
        printf("Está balanceado");
    }
    fclose(entrada);
    return 0;
}