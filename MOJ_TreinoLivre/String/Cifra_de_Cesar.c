#include <stdio.h>
#include <stdlib.h>

#define TAM_LINHA 1001

int main(void) {
    int n;
    char buffer[10];
    fgets(buffer, sizeof(buffer),stdin);
    sscanf(buffer, "%d", &n);
    char *linhas[n];
    for (int i=0; i<n; i++){
        linhas[i] = malloc(TAM_LINHA);
        fgets(linhas[i], TAM_LINHA, stdin);
    }

    for (int i=0; i < n; i++){
        for (int j=0; j < TAM_LINHA; j++) {
            if (linhas[i][j] == '\0') break;
            if ((linhas[i][j] >= 'D') && (linhas[i][j] <= 'Z')) {
                fputc(linhas[i][j] - 3, stdout);
                continue;
            }
            switch (linhas[i][j]) {
                case 'A' : fputc('X', stdout); break;
                case 'B' : fputc('Y', stdout); break;
                case 'C' : fputc('Z', stdout); break;
                default : fputc(linhas[i][j], stdout); break; 
            }
        }
    }

    for (int i=0; i<n; i++){
        free(linhas[i]);
    }
    return 0;
}
