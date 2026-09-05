#include <stdio.h>

#define TAM_LINHA1 1002
#define TAM_LINHAN 30
char buffer[TAM_LINHAN];


int main(void) {
    int letras[26];
    static char linha1[TAM_LINHA1];
    fgets(linha1, TAM_LINHA1, stdin);

    while (fgets(buffer, TAM_LINHAN, stdin)) {
        int num;
        sscanf (buffer+2, "%d", &num);
        letras[buffer[0] - 'A'] =  num;
    }

    
    
    return 0;
}
