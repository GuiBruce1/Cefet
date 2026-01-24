#include <iostream>
using namespace std;
//lista circular dupla
typedef struct no{
    char nome[30];
    struct no *prox;
    struct no *ant;
}No;

typedef No* ptrNo;

void adiciona(ptrNo *i, ptrNo *f){
    ptrNo p = new No;

    cout<<"Digite o nome: ";
    cin>>p->nome;

    if(*i == NULL){
        *i=*f=p;
        p->prox = p;
        p->ant = p;
    }else{
        (*f)->prox = p;
        p->ant = *f;
        *f = p;
        p->prox = *i;
        (*i)->ant = p;
    }
}
void remove(ptrNo *i, ptrNo *f){
    ptrNo p = *i;

    if(p == NULL){
        cout<<"Lista já está vazia!"<<endl;
    }else if( *i == *f){
        delete(p);
        *i=*f=NULL;
    }else{
        (*i)= (*i)->prox;
        (*i)->ant = *f;
        (*f)->prox = *i;
        delete(p);
    }
}
void imprime(ptrNo *i,ptrNo *f){
    ptrNo p = *i;

    if(p ==  NULL){
        cout<<"Lista está vazia!"<<endl;
    }else if(*i == *f){
        cout<<p->nome<<endl;
    }else{
        do{
            cout<<p->nome<<"->";
            p = p->prox;
        }while(p != *i);
        cout<<endl;
    }
}

main(){
    ptrNo topo = NULL;
    ptrNo fim = NULL;

    int entrada;

    do{
        //blablabla 1 2 3 
        cout<<"0 sai, 1 adiciona, 2 remove, 3 imprime"<<endl;
        cin>>entrada;
        switch(entrada){
            case 0: cout<<"Saindo..."; break;
            case 1: adiciona(&topo, &fim); break;
            case 2: remove(&topo, &fim); break;
            case 3: imprime(&topo, &fim); break;
        }
    }while(entrada != 0);
}