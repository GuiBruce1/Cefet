#include <iostream>
using namespace std;

// Estrutura do nó da árvore
struct no {
    int info;
    struct no *esq, *dir;
};
typedef struct no* noPtr;

// Função para verificar se o nó está vazio
bool enderecoVazio(noPtr p) {
    return p == nullptr;
}

// Função para inserir um nó na árvore
void inserir(noPtr* p, int x) {
    if (enderecoVazio(*p)) {
        *p = new no;
        (*p)->info = x;
        (*p)->esq = nullptr;
        (*p)->dir = nullptr;
    } else {
        if (x < ((*p)->info))
            inserir(&((*p)->esq), x);
        else
            inserir(&((*p)->dir), x);
    }
}

// Função para buscar um elemento na árvore
bool buscar(noPtr p, int x) {
    if (enderecoVazio(p)) {
        cout << "\nArvore nao possui elementos" << endl;
        return false;
    }

    if (x == p->info) {
        cout << "\nO elemento: " << p->info << " foi encontrado!\n";
        return true;
    } else if (x < p->info) {
        return buscar(p->esq, x);
    } else {
        return buscar(p->dir, x);
    }
}

// Funções para exibir a árvore em diferentes ordens
void listarEmOrdem(noPtr p) {
    if (!enderecoVazio(p)) {
        listarEmOrdem(p->esq);
        cout << "\t" << p->info;
        listarEmOrdem(p->dir);
    }
}

void listarPreOrdem(noPtr p) {
    if (!enderecoVazio(p)) {
        cout << "\t" << p->info;
        listarPreOrdem(p->esq);
        listarPreOrdem(p->dir);
    }
}

void listarPosOrdem(noPtr p) {
    if (!enderecoVazio(p)) {
        listarPosOrdem(p->esq);
        listarPosOrdem(p->dir);
        cout << "\t" << p->info;
    }
}

// Função para encontrar o maior elemento da subárvore esquerda
noPtr maior(noPtr* p) {
    if ((*p)->dir == nullptr) {
        noPtr t = *p;
        *p = (*p)->esq;
        return t;
    }
    return maior(&((*p)->dir));
}

// Função para remover um nó da árvore
void remover(noPtr* p, int x) {
    if (enderecoVazio(*p)) {
        cout << "\nElemento nao encontrado na árvore.\n";
        return;
    }

    if (x < (*p)->info) {
        remover(&((*p)->esq), x);
    } else if (x > (*p)->info) {
        remover(&((*p)->dir), x);
    } else {
        noPtr aux = *p;
        if ((*p)->esq == nullptr) {
            *p = (*p)->dir;
        } else if ((*p)->dir == nullptr) {
            *p = (*p)->esq;
        } else {
            aux = maior(&((*p)->esq));
            (*p)->info = aux->info;
        }
        delete aux;
        cout << "\nO elemento foi removido\n";
    }
}

// Função de menu
int menu() {
    int op;
    cout << "\nMENU:";
    cout << "\n1 - Inserir";
    cout << "\n2 - Remover";
    cout << "\n3 - Listar";
    cout << "\n4 - Buscar";
    cout << "\n0 - Sair";
    cout << "\nEscolha uma opcao: ";
    cin >> op;
    return op;
}

// Função para escolher o tipo de listagem
int listarNos() {
    int op;
    cout << "\n1 - Em ordem";
    cout << "\n2 - Pre-ordem";
    cout << "\n3 - Pos-ordem";
    cout << "\nEscolha uma opcao: ";
    cin >> op;
    return op;
}

// Função principal
int main() {
    int op1, op2, x;
    bool achei;
    noPtr raiz = nullptr;

    do {
        op1 = menu();
        switch (op1) {
            case 1:
                cout << "\nElemento a inserir: ";
                cin >> x;
                inserir(&raiz, x);
                break;
            case 2:
                cout << "\nElemento para remover: ";
                cin >> x;
                remover(&raiz, x);
                break;
            case 3:
                op2 = listarNos();
                if (op2 == 1) listarEmOrdem(raiz);
                if (op2 == 2) listarPreOrdem(raiz);
                if (op2 == 3) listarPosOrdem(raiz);
                cout << endl;
                break;
            case 4:
                cout << "\nElemento para buscar: ";
                cin >> x;
                achei = buscar(raiz, x);
                if (!achei) cout << "Elemento nao encontrado.\n";
                break;
        }
    } while (op1 != 0);

    return 0;
}
