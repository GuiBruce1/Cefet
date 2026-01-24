#include <iostream> 
#include <stdlib.h>
using namespace std;

typedef struct no{
    int idade;
    struct no *prox;
}No;

typedef No* ptrNo;

ptrNo topo = NULL;

void push(){
    int valor;
    ptrNo novo = (ptrNo) malloc(sizeof(No));

    if(novo){
        cout<<"Digite sua idade: ";
        cin>>valor;
        novo->idade = valor;
        novo->prox = topo;
        topo = novo;

    }else{
        cout<<"Alocação falhou!\n";
    }
}

void pop(){
    ptrNo remove = topo;

    if(topo != NULL){
        topo = topo->prox;
        cout<<"Idade removida: " << remove->idade << "\n";
        free(remove);

    }else{
        cout<<"Pilha já está vazia!\n";
    }

}

main(){

    int entrada;

    do{
        cout<<"Digite 0 para encerrar\n1 para adicionar um elemento\n2 para remover um elemento\n3 para imprimir a pilha\n";
        cin>>entrada;
        switch(entrada){
            case 0: 
                break;
            case 1: 
                push(); break;
            case 2: 
                pop(); break;
            case 3:
                if(topo != NULL){
                    ptrNo aux = topo;
                    while(aux != NULL){
                        cout<<aux->idade<<"\n";
                        aux = aux->prox;
                    }

                }else{
                    cout<<"A pilha está vazia!\n";
                }break;
        }
    }while(entrada != 0);




}