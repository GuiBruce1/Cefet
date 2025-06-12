#include <stdio.h>

typedef struct _HashElement{
    int uf;
    float soma;
    int qt;
    HashElement *next;
}HashElement;

void acumula(HashElement tabela[], int uf, float peso){
    int pos = uf%31;
    HashElement *x = &tabela[pos];
    while (x){
        if(x->uf == uf){
            x->soma += peso;
            x->qt++;
            return;
        }
        x = x->next;
    }
    if(tabela[pos].uf == 0){
        tabela[pos].uf = uf;
        tabela[pos].soma = peso;
        tabela[pos].qt = 1;
    }else{
        x = (HashElement*) malloc(sizeof(HashElement));
        x->uf = uf;
        x->soma = peso;
        x->qt = 1;
        x->next = tabela[pos].next;
        tabela[pos].next = x;
    }
    
}


int main(){

}