#include <stdio.h>
#include <string.h>
#define Num_de_Alunos 3

typedef struct aluno Aluno;

struct aluno{
    char nome[31];
    int idade;
    float peso;
    float altura;
    char nome_Atividade[31];
};

void leDados(Aluno a[]){
    for(int i = 0; i < Num_de_Alunos; i++){
        printf("Dados da %do\n", i+1);
        scanf(" %s", a[i].nome);
        scanf("%d", &a[i].idade);
        scanf("%f", &a[i].peso);
        scanf("%f", &a[i].altura);
        scanf(" %s", a[i].nome_Atividade);
    }
}

void imprimeDados(Aluno a[]){
    for(int i = 0; i < Num_de_Alunos; i++){
        printf(" %s\n", a[i].nome);
        printf("%d\n", a[i].idade);
        printf("%.2f\n", a[i].peso);
        printf("%.2f\n", a[i].altura);
        printf(" %s\n", a[i].nome_Atividade);
    }
}

void atualizacaoDados(Aluno a[]){
    char aux[31];
    scanf("%s", aux);
    for(int i = 0; i < Num_de_Alunos; i++){
        if(strcmp(a[i].nome,aux) == 0){
            scanf(" %s", a[i].nome);
            scanf("%d", &a[i].idade);
            scanf("%f", &a[i].peso);
            scanf("%f", &a[i].altura);
            scanf(" %s", a[i].nome_Atividade);
        }
    }
}

void removeAluno(Aluno a[]){
    char aux[31] = {0};
    scanf("%s", aux);

    for(int i = 0; i < Num_de_Alunos; i++){
        if(strcmp(a[i].nome,aux) == 0){
            memset(&a[i], 0, sizeof(Aluno));//zera a struct toda
        }
    }

}

void bubbleSort(Aluno a[]) {
    Aluno a2;
    for (int i = Num_de_Alunos - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (strcmp(a[j].nome, a[j + 1].nome) > 0) {
                a2 = a[j];
                a[j] = a[j+1];
                a[j+1] = a2;
            }
        }
    }
}

int main(){
    Aluno a[Num_de_Alunos];
    float imc = 0.0;

    leDados(a);
    imprimeDados(a);
    bubbleSort(a);

    for(int i = 0; i < Num_de_Alunos; i++){
        printf("%s\n", a[i].nome);
        printf("%d\n", a[i].idade);
        printf("%.2f\n", a[i].peso);
        printf("%.2f\n", a[i].altura);
        printf("%s\n", a[i].nome_Atividade);
        imc = a[i].peso/(a[i].altura * a[i].altura);
        printf("%.2f\n", imc);
    }

    return 0;
}