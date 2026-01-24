#include <iostream>
using namespace std;

typedef struct consumo{
    int cod; 
    struct consumo *pr;
}Consumo;

typedef Consumo* ptrConsumo;

typedef struct no{
    int info; 
    ptrConsumo consumo; 
    struct no *prox;
    struct no *ant;
}No;

typedef No* ptrNo;

int codigoCliente = 100;

void chegadaCliente(ptrNo *t, ptrNo *f){
    ptrNo novo = new No;
    novo->info = codigoCliente;
    novo->consumo = NULL;
    codigoCliente += 100;

    if(*t == NULL){
        *t = *f = novo;
        novo->prox = novo->ant = novo;
    }else{
        (*f)->prox = novo;
        novo->ant = *f;
        novo->prox = *t;
        (*t)->ant = novo;
        *f = novo;
    }

    cout<<"Cliente "<< novo->info <<" adicionado com sucesso!\n";
}

void consumoCliente(ptrNo t){
    int codigo, produto;
    cout<<"Digite o codigo do cliente: ";
    cin>> codigo;
    
    ptrNo aux = t;
    bool encontrado = false;
    if(aux != NULL){
        do{
            if(aux->info == codigo){
                encontrado = true;
                ptrConsumo novoConsumo = new Consumo;
                cout<<"Digite o codigo do produto: ";
                cin>> produto;
                novoConsumo->cod = produto;
                novoConsumo->pr = aux->consumo;
                aux->consumo = novoConsumo;
                cout <<"Pedido realizado com sucesso!\n";
                break;
            }
            aux = aux->prox;
        }while(aux != t);
    }
    if(!encontrado){
        cout<<"Cliente nao encontrado!\n";
    }
}

void saidaCliente(ptrNo *t, ptrNo *f){
    int codigo;
    cout<<"Digite o codigo do cliente para saida: ";
    cin>> codigo;
    
    ptrNo aux = *t;
    bool encontrado = false;
    if(aux != NULL){
        do{
            if(aux->info == codigo){
                encontrado = true;
                cout<<"Consumo do cliente "<< codigo << ": ";
                ptrConsumo c = aux->consumo;
                while(c != NULL){
                    cout << c->cod << " ";
                    ptrConsumo temp = c;
                    c = c->pr;
                    delete temp;
                }
                cout << endl;

                if(*t == *f){
                    delete aux;
                    *t = *f = NULL;
                }else{
                    aux->ant->prox = aux->prox;
                    aux->prox->ant = aux->ant;
                    if (aux == *t) *t = aux->prox;
                    if (aux == *f) *f = aux->ant;
                    delete aux;
                }

                cout<<"Cliente numero "<< codigo <<" liberado.\n";
                break;
            }
            aux = aux->prox;
        }while(aux != *t);
    }
    if(!encontrado){
        cout<<"Cliente nao encontrado!\n";
    }
}

void imprimeClientes(ptrNo t){
    if(t == NULL){
        cout << "Lista de clientes vazia!\n";
    }else{
        ptrNo aux = t;
        do {
            cout<<"Cliente: "<< aux->info <<" | Consumos: ";
            ptrConsumo c = aux->consumo;
            while(c != NULL){
                cout << c->cod << " ";
                c = c->pr;
            }
            cout << endl;
            aux = aux->prox;
        } while(aux != t);
    }
}

int main(){
    ptrNo t = NULL;
    ptrNo f = NULL;
    int entrada;

    do{
        cout<<"0 - Sair\n1 - Chegada Cliente\n2 - Consumo Cliente\n3 - Saida Cliente\n4 - Imprime Clientes\n";
        cin>>entrada;
        switch(entrada){
            case 0: cout << "Saindo...\n"; break;
            case 1: chegadaCliente(&t, &f); break;
            case 2: consumoCliente(t); break;
            case 3: saidaCliente(&t, &f); break;
            case 4: imprimeClientes(t); break;
        }
    }while(entrada != 0);

    return 0;
}
