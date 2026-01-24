#include <stdio.h>

int calcularMDC(int a, int b) {
    int mdc, i, maior, menor;
    
    if (a < b) {
        maior = b;
        menor = a;
    } else if (b < a) {
        maior = a;
        menor = b;
    } else {
        mdc = a;
        return mdc;
    }
    i = maior%menor;
    while (i != 0) {
        maior = menor;
        menor = i;
        i = maior%menor;
    }
    mdc = menor;
    return (mdc);

}

int main() {
    int a, b, mdc;


    printf("Insira os dois números que deseja saber o MDC:");
    scanf("%d %d", &a, &b);
    if (a <= 0 || b <= 0) {
        printf("Insira um valor positivo");
        return 1;
    }

    mdc = calcularMDC(a, b);
    printf("MDC = %d", mdc);

    return 0;


}