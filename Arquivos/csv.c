#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//vai cair na prova que o EOF é um estado, para que o EOF seja dectado o arquivo tem que ter sido lido, se um arquivo mesmo vazio nn for lido, nn vai ser detectado o EOF

//awk no windows para automatos 

// tive que implementar o codigo fonte para parar de dar problema no windows
/*char* strtok_r(
    char *str, 
    const char *delim, 
    char **nextp)
{
    char *ret;

    if (str == NULL)
    {
        str = *nextp;
    }

    str += strspn(str, delim);

    if (*str == '\0')
    {
        return NULL;
    }

    ret = str;

    str += strcspn(str, delim);

    if (*str)
    {
        *str++ = '\0';
    }

    *nextp = str;

    return ret;
}*/

int main(int argc, char** argv){

    FILE *entrada = fopen("teste.csv","r");
    char buffer[4016];
    //para linux strtok_r, pra windows strtok_s(mesmo assim nn ta deixando compilar)
    fgets(buffer, 4016, entrada);
    while(!feof(entrada)){
        fgets(buffer,4016,entrada);
        char *x;
        char *t = strtok_r(buffer,";\n",&x);
        while(t){
            printf("Token %s\n", t);
            t =  strtok_r(NULL,",\n",&x);
        }
    }
    fclose(entrada);
    return 0;
}