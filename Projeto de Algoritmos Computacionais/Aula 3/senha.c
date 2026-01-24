/*login, Guilherme Bruce*/

#include <stdio.h>

int main()
{
    int tentativa;
    tentativa=1;
    int matricula; 
    int senha;


while (tentativa<=3)
{
    printf("Insira sua matricula\n ");
    scanf("%d", &matricula);

    printf("Insira sua senha\n ");
    scanf("%d", &senha);
    
    tentativa=tentativa+1;

    
        if (matricula == 7892457 && senha == 123321)
        {
            printf("Bem vindo Anakin Skywalker\n ");
        }
        if (matricula == 5425376 && senha == 812837)
        {
            printf("Bem vinda Leia Organa\n ");
        }
        if (matricula == 2736252 && senha == 273625)
        {
            printf("Bem vindo Luke Skywalker\n ");
        }
        if ((matricula != 7892457 && senha != 123321) && (matricula != 5425376 && senha != 812837) && (matricula != 2736252 && senha != 273625)) 
        {
            printf("Matricula ou senha incorreta, tente novamente\n ");
        }
}

    printf("Voce excedeu as suas 3 entradas!");

    return 0;
}









   
   
   
