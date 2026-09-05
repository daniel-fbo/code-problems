#include <stdio.h>
#include <stdlib.h>

#define QTD_FRASE 101
#define TAM_FRASE 101
#define TAM_QUERY 20

int main(void) {
    int input[3];
    char buffer[200];
    char *frases[2][QTD_FRASE]; int *q[51];

    fgets(buffer,sizeof(buffer),stdin);
    sscanf(buffer, "%d%d%d", input, input+1,input+2);

    for (int i = 0; i < input[0] + input[1]; i++){
        if (input[0] > i) {
            frases[0][i] = malloc(TAM_FRASE);
            fgets(frases[0][i],TAM_FRASE,stdin);
        } else {
            frases[1][i - input[0]] = malloc(TAM_FRASE);
            fgets(frases[1][i - input[0]],TAM_FRASE,stdin);
        }
    }

    for (int i = 0; i < input[2]; i++){
        char temp[50];
        q[i] = malloc(TAM_QUERY);
        fgets(temp,sizeof(temp),stdin);
        sscanf(temp, "%d%d%d", q[i], q[i] + 1, q[i] + 2);
    }

    for (int i = 0; i < input[2]; i++){
        fprintf(stdout,"%s",frases[q[i][0] - 1][q[i][1] - 1] + q[i][2]);
    }


    for (int i = 0; i < input[0] + input[1]; i++){
        if (input[0] > i) {
            free(frases[0][i]);
        } else {
            free(frases[1][i - input[0]]);
        }
    }

    for (int i = 0; i < input[2]; i++){
        free(q[i]);
    }
    return 0;
}
