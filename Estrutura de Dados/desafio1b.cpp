#include <iostream>
#include <string>
using namespace std;

struct No{
    string texto; 
    No* prox;     
    No* ant;      
};

void inserir(No** topo, No** fim, const string& linha){
    No* novo = new No;
    novo->texto = linha;
    novo->prox = nullptr;
    novo->ant = *fim;

    if(*fim != nullptr){
        (*fim)->prox = novo;
    }
    *fim = novo;

    if(*topo == nullptr){
        *topo = novo;
    }

    cout<<"Linha inserida com sucesso!\n";
}

void excluir(No** topo, No** fim, int linha){
    if(*topo == nullptr){
        cout<<"O texto está vazio.\n";
        return;
    }

    No* atual = *topo;
    int cont = 1;

    while(atual != nullptr && cont < linha){
        atual = atual->prox;
        cont++;
    }

    if(atual == nullptr){
        cout<<"Linha "<< linha <<" não encontrada.\n";
        return;
    }

    if(atual->ant != nullptr){
        atual->ant->prox = atual->prox;
    }else{
        *topo = atual->prox;
    }

    if(atual->prox != nullptr){
        atual->prox->ant = atual->ant;
    }else{
        *fim = atual->ant;
    }

    delete atual;
    cout<<"Linha "<< linha <<" excluída com sucesso.\n";
}

void listar(No* fim){
    if(fim == nullptr){
        cout<<"O texto está vazio.\n";
        return;
    }

    No* atual = fim;
    while(atual != nullptr){
        cout<<atual->texto<<endl;
        atual = atual->ant;
    }
}

void mover(No** topo, No** fim, int l1, int l2){
    if(*topo == nullptr){
        cout<<"O texto está vazio.\n";
        return;
    }

    No* atual = *topo;
    int cont = 1;

    while(atual != nullptr && cont < l1){
        atual = atual->prox;
        cont++;
    }

    if(atual == nullptr){
        cout<<"Linha "<< l1 <<" não encontrada.\n";
        return;
    }

    if(atual->ant != nullptr){
        atual->ant->prox = atual->prox;
    }else{
        *topo = atual->prox;
    }

    if(atual->prox != nullptr){
        atual->prox->ant = atual->ant;
    }else{
        *fim = atual->ant;
    }

    No* destino = *topo;
    cont = 1;

    while(destino != nullptr && cont < l2){
        destino = destino->prox;
        cont++;
    }

    if(destino == nullptr){ 
        atual->prox = nullptr;
        atual->ant = *fim;
        if(*fim != nullptr){
            (*fim)->prox = atual;
        }
        *fim = atual;
        if(*topo == nullptr){
            *topo = atual;
        }
    }else{ 
        atual->prox = destino;
        atual->ant = destino->ant;

        if(destino->ant != nullptr){
            destino->ant->prox = atual;
        }else{
            *topo = atual;
        }
        destino->ant = atual;
    }

    cout<<"Linha "<< l1 <<" movida para a posição "<< l2 <<".\n";
}

int main(){
    No* topo = nullptr;
    No* fim = nullptr;
    int opcao, l1, l2;
    string linha;

    do{
        cout<<"\nMenu:\n";
        cout<<"0 - Sair\n";
        cout<<"1 - Inserir\n";
        cout<<"2 - Excluir\n";
        cout<<"3 - Listar\n";
        cout<<"4 - Mover\n";
        cout<<"Escolha uma opção: ";
        cin>>opcao;

        switch(opcao){
            case 0:
                cout<<"Encerrando...\n";
                break;
            case 1:
                cout<<"Digite a linha a ser inserida: ";
                cin.ignore(); 
                getline(cin, linha);
                inserir(&topo, &fim, linha);
                break;
            case 2:
                cout<<"Digite o número da linha a ser excluída: ";
                cin>>l1;
                excluir(&topo, &fim, l1);
                break;
            case 3:
                listar(fim);
                break;
            case 4:
                cout<<"Digite o número da linha a ser movida (L1): ";
                cin>>l1;
                cout<<"Digite o número da posição de destino (L2): ";
                cin>>l2;
                mover(&topo, &fim, l1, l2);
                break;
            default:
                cout<<"Opção inválida.\n";
        }
    }while(opcao != 0);

    return 0;
}
