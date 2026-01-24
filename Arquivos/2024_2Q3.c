#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct dados{
    int matricula;
    //outros dados
}Dados;

int main(int argc, char** argv){

    FILE *entrada;
    FILE *entrada2;
    FILE *saida;
    Dados buffer;
    Dados buffer2;
    long tam;
    int qtdRegistro;
    int encontrado;
    int inicio = 0;
    int fim;
    int meio;


    entrada = fopen(argv[1],"rb");
    entrada2 = fopen(argv[2],"rb");
    saida = fopen("arquivoDestino.dat","wb");

    fseek(entrada2, 0, SEEK_END);
    tam = ftell(entrada2);
    qtdRegistro = tam / sizeof(Dados);
    rewind(entrada2);

    do{
        encontrado = 0;
        inicio = 0;
        fim = qtdRegistro - 1;
        while(inicio <= fim){
            meio = (inicio + fim) / 2;
            fseek(entrada2, meio * sizeof(Dados), SEEK_SET);
            fread(&buffer2, sizeof(Dados), 1, entrada2); 
            
            if(buffer.matricula == buffer2.matricula){
                encontrado = 1;
                break;
            }else if(buffer.matricula < buffer2.matricula){
                fim = meio - 1;
            }else{
                inicio = meio + 1;
            }
        }
        if(encontrado == 0){
            fwrite(&buffer, sizeof(Dados), 1, saida);
        }
    }while(fread(&buffer,sizeof(Dados),1,entrada) == 1);
    
    fclose(entrada);
    fclose(entrada2);
    fclose(saida);
    return 0;
}