#include <iostream>
using namespace std;
#define n 10
//pesquisar sobre o insertion sort, ver diferenças, características, qual que eu gosto mais

int main() {
    int i, A[n], menor, j, aux;
    for(i=0; i<n; i++){
        cout << "Digite o valor do" <<i+1<< "o. elemento: ";//é um printf
        cin >> A[i]; // é um scanf
    }
   
    for(i=0; i<n-1; i++){
        menor = i;
        for(j=i+1; j<n; j++){
            if(A[menor]>A[j]){
                menor = j;
            }
        }
        if(menor!=i){
            aux = A[i];
            A[menor]=A[i];
            A[menor]= aux;
        }
    }
    for(i=0; i<n; i++){
        cout << "\nValores em ordem crescente: " << i;
    }
    return 0;
}