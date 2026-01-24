#include <stdio.h>

int valida_triangulo(int a, int b , int c)
{
    return ( ((a + b) > c) && ((a + c) > b) && ((b + c) > a) );
}

int main()
{
    int a, b, c;
    printf("Digite os lados do seu triangulo e classificaremos ele se esse for valido ");
    scanf("%d %d %d", &a, &b, &c);

    if (valida_triangulo(a, b, c))
    {
        if (a==b && a==c && b==c)
        {
            printf("Seu triangulo e valido e foi classificado como equilatero");
        }
        if (a==b && a!=c && b!=c || b==c && b!=a && c!=a || a==c && a!=b && c!=b)
        {
            printf("Seu triangulo e valido e foi classificado como isosceles");
        }
        if (a!=b && a!=c && b!=c)
        {
            printf("Seu triangulo e valido e foi classificado como escaleno");
        }
    }
    else 
    {
        printf("Seu triangulo e invalido");
    }

    return 0;
}