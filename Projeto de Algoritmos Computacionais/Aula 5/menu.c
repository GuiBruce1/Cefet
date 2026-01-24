#include <stdio.h>

int menuPrincipal()
{
    int op;
    printf("Menu Principal");
    printf("1. Incluir\n");
    printf("2. Excluir\n");
    printf("3. Alterar\n");
    printf("4. Consultar\n");
    printf("5. Relatório\n");
    printf("6. Fim\n");
    
    printf("Escolha uma opção: ");
    do 
    {
        printf("Entre com a opção; ");
        scanf("%d", &op);
    }while (op < 0 || op > 6);


}