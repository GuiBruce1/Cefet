#include <iostream>

// Função para trocar dois elementos
void troca(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para restaurar a propriedade do heap subindo um elemento
void subir(int A[], int i) {
    int j = (i - 1) / 2; // Índice do pai
    if (j >= 0 && A[i] > A[j]) {
        troca(&A[i], &A[j]);
        subir(A, j);
    }
}

// Função para restaurar a propriedade do heap descendo um elemento
void descer(int A[], int i, int q) {
    int d = 2 * i + 2; // Filho direito
    int e = 2 * i + 1; // Filho esquerdo
    int maior = i;

    if (d <= q && A[d] > A[maior])
        maior = d;
    if (e <= q && A[e] > A[maior])
        maior = e;
    if (maior != i) {
        troca(&A[i], &A[maior]);
        descer(A, maior, q);
    }
}

// Função para inserir um elemento no heap
void inserir(int A[], int valor, int* t) {
    *t = *t + 1;
    A[*t] = valor;
    subir(A, *t);
}

// Função para remover o maior elemento (raiz do heap)
void remover(int A[], int* q) {
    A[0] = A[*q]; // Substitui a raiz pelo último elemento
    *q = *q - 1;
    descer(A, 0, *q);
}

// Função para exibir os elementos do heap
void exibir(int A[], int tamanho) {
    for (int i = 0; i <= tamanho; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int heap[100]; // Vetor para armazenar o heap
    int tamanho = -1; // Índice do último elemento do heap

    // Inserção de elementos no heap
    inserir(heap, 10, &tamanho);
    inserir(heap, 20, &tamanho);
    inserir(heap, 15, &tamanho);
    inserir(heap, 30, &tamanho);
    inserir(heap, 40, &tamanho);
    inserir(heap, 50, &tamanho);

    std::cout << "Heap após inserções: ";
    exibir(heap, tamanho);

    // Removendo o maior elemento
    remover(heap, &tamanho);
    std::cout << "Heap após remoção: ";
    exibir(heap, tamanho);

    return 0;
}

/*
Para modificar o código para um heap one-based, as seguintes alterações são necessárias:
1. O índice inicial do heap deve ser 1 em vez de 0.
2. A função `subir` deve calcular o pai com `i / 2` em vez de `(i - 1) / 2`.
3. A função `descer` deve calcular os filhos com `2 * i` e `2 * i + 1` em vez de `2 * i + 1` e `2 * i + 2`.
4. O tamanho do heap deve ser inicializado em 0 em vez de -1.
5. As funções de acesso ao array devem ser ajustadas para refletir o novo índice base (1 em vez de 0).
*/
