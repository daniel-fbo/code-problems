#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 50
#define TAM_MIN 20
char buffer[TAM_MAX];

int main(void) {
    char *frases[2];
    
    frases[0] = malloc(TAM_MIN);
    frases[1] = malloc(TAM_MIN);

    fgets(buffer, TAM_MAX, stdin);
    sscanf(buffer, "%s%s", frases[0], frases[1]);

    switch (frases[0][0]){
        case 'n':
            switch (frases[1][0]){
                case 'n' : fprintf(stdout, "%d\n", 0); break;
                case 'l' : fprintf(stdout, "%d\n", 90); break;
                case 'o' : fprintf(stdout, "%d\n", 90); break;
                case 's' : fprintf(stdout, "%d\n", 180); break;
            }
            break;
        case 'l':
            switch (frases[1][0]){
                case 'n' : fprintf(stdout, "%d\n", 90); break;
                case 'l' : fprintf(stdout, "%d\n", 00); break;
                case 'o' : fprintf(stdout, "%d\n", 180); break;
                case 's' : fprintf(stdout, "%d\n", 90); break;
            }
            break;
        case 'o':
            switch (frases[1][0]){
                case 'n' : fprintf(stdout, "%d\n", 90); break;
                case 'l' : fprintf(stdout, "%d\n", 180); break;
                case 'o' : fprintf(stdout, "%d\n", 0); break;
                case 's' : fprintf(stdout, "%d\n", 90); break;
            }
            break;
        case 's':
            switch (frases[1][0]){
                case 'n' : fprintf(stdout, "%d\n", 180); break;
                case 'l' : fprintf(stdout, "%d\n", 90); break;
                case 'o' : fprintf(stdout, "%d\n", 90); break;
                case 's' : fprintf(stdout, "%d\n", 0); break;
            }
            break;
    }

    free (*(frases));
    free (*(frases+1));
    return 0;
}
