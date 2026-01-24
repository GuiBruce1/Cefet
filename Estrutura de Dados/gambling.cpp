#include <iostream>
#include <cstdlib>
using namespace std;


typedef struct no{
    int num;
    struct no *prox;
    
}No;

typedef No* ptrNo;

ptrNo bolinha = NULL;



void adiciona(ptrNo *i, ptrNo *f){
    ptrNo p = new No;
    ptrNo aux = *i;

    cout<<"Digite o nome: ";
    unsigned seed = time(0);
    srand(seed);
    p->num = rand()%39;
    do{
        if(p->num == aux->num){
            p->num = rand()%39;
        }
        aux = aux->prox;
    }while(aux != *i);

    if(*i == NULL){
        *i=*f=p;
        p->prox = p;
        //p->ant = p;
    }else{
        (*f)->prox = p;
        //p->ant = *f;
        *f = p;
        p->prox = *i;
        //(*i)->ant = p;
    }
}


main(){


    ptrNo topo = NULL;
    ptrNo fim = NULL;

    for(int i = 0;i < 37; i++){
        adiciona(&topo, &fim);
    }
}
