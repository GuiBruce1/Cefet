#include <stdio.h>
#include <math.h>

int main(){
    float a, b, c, delta, x1, x2, x;
    //leia (a,b,c)
    //escreva (" Entre com os valores de a , b , c:")
    printf("Insira um valor para os coeficientes A, B e C: ");
    scanf("%f%f%f",&a,&b,&c);
    delta = b*b-4*a*c;
    if (delta > 0){
        x1= (-b + sqrt(delta)) / (2*a);
        x2= (-b - sqrt(delta)) / (2*a);
        printf("Raízes são: %f e %f,",x1,x2);

    }
    if (delta < 0) {
        printf("Nao existe raiz real");

    }
    if (delta == 0) {
        x = (-b)/(2*a);
        printf("Uma raiz: %f", x);
    
    }
    return 0;
}