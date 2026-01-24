#include <stdio.h>


int main(){

    int x;
    int maior;
    
    for (int i = 0; i < 10; i++)
    {
        printf("Insira o %do número\n", i+1);
        scanf("%d", &x);
        if (i==0 || x > maior)
        {
            maior = x;
        }
    }
    printf("O maior número é %d\n", maior);
    return 0;
}