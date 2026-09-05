#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM_MAX 158

int main(void) {
    char buffer[TAM_MAX], dd[3], N;
    int num;
    char C[13] = {0}, E[13] = {0}, U[13] = {0}, P[13] = {0}; 
    int faltaC = 0, faltaE = 0, faltaU = 0, faltaP = 0;
    bool duplicatedC = false, duplicatedE = false, duplicatedU = false, duplicatedP = false;

    fgets(buffer, sizeof(buffer), stdin);

    for (int i = 0; i < TAM_MAX; i += 3){
        if (buffer[i] == '\n') break;
        dd[0] = buffer[i]; dd[1] = buffer[i+1]; N = buffer[i+2];
        num = atoi (dd) - 1;
        switch (N){
            case 'C': if (C[num] == 1) {duplicatedC = true;} else {C[num] = 1;} break;  
            case 'E': if (E[num] == 1) {duplicatedE = true;} else {E[num] = 1;} break;
            case 'U': if (U[num] == 1) {duplicatedU = true;} else {U[num] = 1;} break;
            case 'P': if (P[num] == 1) {duplicatedP = true;} else {P[num] = 1;} break;
        }
    }


    for (int i = 0; i<13; i++){
        if (C[i] == 0) faltaC++;
        if (E[i] == 0) faltaE++;
        if (U[i] == 0) faltaU++;
        if (P[i] == 0) faltaP++;
    }

    if (duplicatedC == true) {fprintf(stdout, "erro\n");} else {fprintf(stdout, "%d\n",faltaC);}
    if (duplicatedE == true) {fprintf(stdout, "erro\n");} else {fprintf(stdout, "%d\n",faltaE);}
    if (duplicatedU == true) {fprintf(stdout, "erro\n");} else {fprintf(stdout, "%d\n",faltaU);}
    if (duplicatedP == true) {fprintf(stdout, "erro\n");} else {fprintf(stdout, "%d\n",faltaP);}

    return 0;
}
