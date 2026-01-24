/*Média dos alunos*/

#include <stdio.h>

int main() 
{

float p1, p2, p3, media1, media2;

    printf("Informe a nota da sua p1 e p2 ");
    scanf("%f %f", &p1, &p2);

    media1=(p1+p2)/2;

    if (media1>=7) {

    printf("Parabens, voce passou direto!");
    }
    else {
        if (media1<=3) {

            printf("Voce foi reprovado!");
        }
        else {
            if (media1>3 &&  media1<7) {
 
                printf("Voce esta de prova final, insira aqui sua nota da p3 ");
                scanf("%f", &p3);
        
                media2=(media1+p3)/2;
                }
            if (media2>=5) {

                printf("Parabens, voce passou!");
            }
            else {
                if (media2<5) {

                    printf("Voce esta reprovado");
                    }
                }   
            }
        }
            return 0;
}



