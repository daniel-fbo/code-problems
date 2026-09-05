#include <stdio.h>

#define TAM_MAX 25000

int main(void) {
    char buffer[TAM_MAX]; int N = 0;
    int cont = 0, total = 0;

    fgets (buffer, TAM_MAX, stdin);
    sscanf (buffer, "%d", &N);

    fgets (buffer, TAM_MAX, stdin);
    for (int i = 0; cont < N-2; i+=2){
        if (buffer[i] == '1' && buffer[i+2] == '0' && buffer[i+4] == '0') total++;
        cont++;
    }
    fprintf(stdout, "%d\n", total);

    return 0;
}

