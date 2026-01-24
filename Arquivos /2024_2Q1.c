/*1. Desenvolva as fun¸c˜oes solicitadas abaixo, integrantes de um programa em linguagem C para
gerenciar um banco de dados simples de uma cl´ınica veterin´aria utilizando arquivos bin´arios.
Cada animal na cl´ınica dever´a ter as seguintes informa¸c˜oes armazenadas: ID (inteiro, ´unico para
cada animal), Nome (string, at´e 30 caracteres), Esp´ecie (string, at´e 20 caracteres - ex.: c˜ao, gato,
ave, etc.), Idade (inteiro, em anos), Peso (float, em kg). Todas as fun¸c˜oes devem receber como
parˆametro um arquivo j´a aberto.
(a) Buscar registro: Consultar as informa¸c˜oes de um animal a partir do seu identificador ´unico.
O programa deve solicitar o ID do animal. Caso o registro seja encontrado, os dados
devem ser exibidos na tela. Caso contr´ario, uma mensagem indicando que o registro n˜ao foi
encontrado deve ser exibida. (1,0 ponto)
(b) Incluir novo registro: Adicionar informa¸c˜oes de um animal ao banco de dados. O usu´ario
deve informar os dados do animal (ID, Nome, Esp´ecie, Idade e Peso). Esses dados devem ser
adicionados ao arquivo bin´ario no final sem sobrescrever registros existentes. O programa
n˜ao deve aceitar animais com IDs repetidos. (1,0 pontos)
(c) Alterar registro existente: Modificar os dados de um animal a partir do seu identificador
´unico. Todas as informa¸c˜oes antigas daquele registro devem ser apresentadas na tela, em
seguida, o usu´ario dever´a digitar os dados atualizados. (1,0 pontos)*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct _Animal{
    int id;
    char nome[31];
    char especie[21];
    int idade;
    float peso;
}Animal;

void BuscarRegistro(FILE *entrada) {
    int idProcurado;
    Animal buffer;
    int encontrado = 0;

    printf("Insira o ID de seu animal por favor!\n");
    scanf("%d", &idProcurado);

    rewind(entrada); // Garante leitura desde o início

    while(fread(&buffer, sizeof(Animal), 1, entrada) == 1){
        if(buffer.id == idProcurado){
            printf("ID: %d\n", buffer.id);
            printf("Nome: %s\n", buffer.nome);
            printf("Espécie: %s\n", buffer.especie);
            printf("Idade: %d\n", buffer.idade);
            printf("Peso: %.2f kg\n", buffer.peso);
            encontrado = 1;
            break; // já achou, pode parar
        }
    }

    if(encontrado == 0){
        printf("ID não encontrado no banco de dados.\n");
    }
}


void IncluirNovoRegistro(FILE *entrada){
    Animal novo;
    Animal temp;

    printf("Digite as informações do animal (ID, nome, espécie, idade e peso):\n");
    scanf("%d %30s %20s %d %f", &novo.id, novo.nome, novo.especie, &novo.idade, &novo.peso);

    rewind(entrada); // Volta ao início para buscar IDs existentes

    // Verificar se o ID já existe
    while(fread(&temp, sizeof(Animal), 1, entrada) == 1){
        if(temp.id == novo.id){
            printf("Erro: já existe um animal com ID %d.\n", novo.id);
            return 1;
        }
    }

    // Adicionar novo registro ao final
    fseek(entrada, 0, SEEK_END); // Vai ao final do arquivo
    fwrite(&novo, sizeof(Animal), 1, entrada);

    printf("Animal adicionado com sucesso.\n");
}

void alteraRegistroExistente(FILE *entrada){
    int idProcurado;
    Animal buffer;
    int encontrado = 0;
    long posicao;

    printf("Digite o ID do animal que você que alterar as informações: ");
    scanf("%d", &idProcurado);

    while (fread(&buffer, sizeof(Animal), 1, entrada) == 1) {
        if (buffer.id == idProcurado) {
            posicao = ftell(entrada) - sizeof(Animal); // Salva a posição do registro encontrado

            printf("\n--- Dados atuais do animal ---\n");
            printf("ID: %d\n", buffer.id);
            printf("Nome: %s\n", buffer.nome);
            printf("Espécie: %s\n", buffer.especie);
            printf("Idade: %d\n", buffer.idade);
            printf("Peso: %.2f kg\n", buffer.peso);

            printf("\n--- Digite os novos dados ---\n");
            printf("Novo nome: ");
            scanf(" %30s", buffer.nome); // lê com espaços

            printf("Nova espécie: ");
            scanf(" %20s", buffer.especie);

            printf("Nova idade: ");
            scanf("%d", &buffer.idade);

            printf("Novo peso: ");
            scanf("%f", &buffer.peso);

            fseek(entrada, posicao, SEEK_SET); // Volta ao início do registro a ser sobrescrito
            fwrite(&buffer, sizeof(Animal), 1, entrada);

            printf("\nRegistro atualizado com sucesso!\n");

            encontrado = 1;
            break;
        }
    }
    if(encontrado == 0){
        printf("ID não encontrado no banco de dados.\n");
    }


}


int main(int argc, char** argv){

    FILE *entrada;
	
    if(argc != 2)
	{
        fprintf(stderr,"Erro na chamada do comando.\n");
		fprintf(stderr,"Uso: %s [ARQUIVO A SER LIDO].\n", argv[0]);
		return 1;
	}
    entrada = fopen(argv[1],'rb');
    if(!entrada){
        fprintf(stderr, "O arquivo não foi aberto corretamente");
        return 1;
    }

    return 0;
}




