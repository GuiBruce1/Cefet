/*Programa dos descontos de um site*/
#include <stdio.h>

int main()
{
    float valor, desconto;

        printf("Insira o valor total adicionado ao carrinho ");
        scanf("%f", &valor);
    
    if (valor>=600) {
        desconto=valor-(valor*2/10);
    }
    else
    {
        if (valor>=400){ 
            desconto=valor-(valor*15/100); 
        }

        else
        {
             if (valor>=200){ 
                desconto=valor-(valor*1/10); 
            }
    
            else 
    
            { 
                printf("Voce nao obteve descontos "); 
            }       
            }
            }

                printf("Aqui esta o seu desconto %f ", desconto);
                return 0;
}
    







