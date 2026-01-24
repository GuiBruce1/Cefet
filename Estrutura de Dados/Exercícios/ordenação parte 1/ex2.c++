#include <iostream>
using namespace std;


int main(){
    int maior, i, j, somatorio = 0, aux, contador = 0;
    float media;

    int matricula[15] = {12354, 67453, 25432, 98765, 12345, 54321, 67890, 11223, 33445, 55667, 88990, 44556, 77889, 99000, 12312};
    double salarios[15] = {1400, 2300, 4150, 2800, 3600, 4700, 3900, 3000, 4100, 5200, 6000, 7500, 8000, 9100, 10000};
    

    for(i = 0; i < 15-1; i++){
        maior = i;
        somatorio += salarios[i];
        for(j=i+1; j<15; j++){
            if(salarios[maior]<salarios[j]){
                maior = j;
            }
        }
        if(maior!=i){
            aux = salarios[i];
            salarios[maior] = salarios[i];
            salarios[maior] = aux;

            aux = matricula[i];
            matricula[maior] = matricula[i];
            matricula[maior] = aux;


        }
    }

    media = somatorio/15;

    for(i = 0; i < 15; i++){
        cout << "salarios em ordem decrescente: " << salarios[i] << "\n";
    }

    cout << "O somatório dos salários é: " << somatorio << "\n";

    for(i = 0; i < 15; i++){
        if(salarios[i] < media){
            contador++;
            cout << "Salários e matrículas abaixo da média salarial: " << salarios[i] << " " << matricula[i] << "\n";
        }
    }

    cout << "Total de funcionários abaixo da média salarial: " << contador;

    return 0;
}