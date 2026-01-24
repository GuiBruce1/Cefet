#include <iostream>
using namespace std;


typedef struct no{
        char nome[30];
        struct no *prox;
}No;

typedef No* ptrNo;

void adiciona_final(ptrNo *i, ptrNo *f){
    ptrNo p = new No;

    cout << "Digite o nome: ";
    cin >> p->nome;

    if(*i == NULL){
        *i = *f = p;
        p->prox = p; 

    }else{
        (*f)->prox = p;
        (*f) = p;
        p-> prox = *i;
    }
}
void adiciona_inicio(ptrNo *i, ptrNo*f){
    ptrNo p = new No;

    cout << "Digite o nome: ";
    cin >> p->nome;

    if(*i == NULL){
        *i = *f = p;
        p->prox = p; 
    }else{
        p->prox = *i;
        (*f)->prox = p;
        (*i) = p;
    }

}
void remove_final(ptrNo *i, ptrNo *f){
    ptrNo p = *f;
    if(*i == NULL){
        cout<<"Lista já está vazia!";
    }else if(*i == *f){
        delete *i;
        *i = *f = NULL; 
    }else{
        ptrNo aux = *i;
        while (aux->prox != *f) {
            aux = aux->prox;
        }
        delete *f;        
        *f = aux;       
        (*f)->prox = *i ;    
    }
}
void remove_inicio(ptrNo *i, ptrNo *f){
    ptrNo p = *i;
    if(*i == NULL){
        cout<<"Lista já está vazia!";
    }else if(*i == *f){
        delete *i;
        *i = *f = NULL;

    }else{
        (*i) = (*i)->prox;
        delete p;
    }
}
void imprime(ptrNo *i){
    ptrNo p = *i;
    if(p == NULL){
        cout<<"Lista vazia!";
    }else if(p->prox == p){
        cout<< p->nome;
    }else{
        do{
            cout << p->nome << " -> ";
            p = p->prox;
        }while(p != *i);
        
    }
}
main(){

    ptrNo topo = NULL;
    ptrNo final = NULL;

    
    int entrada;
    do{
        //digite blablabla
        cin>> entrada;
        switch(entrada){
            case 0: cout<<"Saindo..."; break;
            case 1: adiciona_inicio(&topo, &final); break;
            case 2: adiciona_final(&topo, &final); break;
            case 3: remove_inicio(&topo, &final); break;
            case 4: remove_final(&topo, &final); break;
            case 5: imprime(&topo); break;
        }

    }while(entrada !=0);
    

}