#include <stdio.h>

double fogo(int nivel);
double agua(int nivel);
double terra(int nivel);
double calculaVantagem(int tipoPlayer, int tipoCPU);
double calculaDano(int tipoPlayer, int nivelPlayer, int tipoCPU, double defesaCPU);

/*int main(void) {
    int num[3]; double number; char buffer[60];
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer,"%d%d%d%lf",num,num+1,num+2,number);

    return 0;
}*/

double fogo(int nivel){
    double mult = 0.0;
    switch (nivel){
        case 1: mult = 2.0; break;
        case 2: mult = 3.0; break;
        case 3: mult = 5.0; break;
    }
    return (mult*100000.000000)/100000.000000;
}
double agua(int nivel){
    double mult = 0.0;
    switch (nivel){
        case 1: mult = 1.0; break;
        case 2: mult = 2.5; break;
        case 3: mult = 4.0; break;
    }
    return (mult*100000.000000)/100000.000000;
}
double terra(int nivel){
    double mult = 0.0;
    switch (nivel){
        case 1: mult = 2.5; break;
        case 2: mult = 5.5; break;
        case 3: mult = 7.0; break;
    }
    return (mult*100000.000000)/100000.000000;
}
double calculaVantagem(int tipoPlayer, int tipoCPU){
    double vant = 0.0;
    switch (tipoPlayer){
        case 1: 
            switch (tipoCPU) {
                case 1: vant = 1.0; break;
                case 2: vant = 0.5; break;
                case 3: vant = 2.0; break;
            }
            break;
        case 2: 
            switch(tipoCPU){
                case 1: vant = 2.0; break;
                case 2: vant = 1.0; break;
                case 3: vant = 0.5; break;
            }
            break;
        case 3:
            switch(tipoCPU){
                case 1: vant = 0.5; break;
                case 2: vant = 2.0; break;
                case 3: vant = 1.0; break;
            }
            break;
    }
    return (vant*100000.000000)/100000.000000;
}
double calculaDano(int tipoPlayer, int nivelPlayer, int tipoCPU, double defesaCPU){
    double dano = 100.0;
    switch (tipoPlayer){
        case 1: dano *= terra(nivelPlayer); break;
        case 2: dano *= fogo(nivelPlayer); break;
        case 3: dano *= agua(nivelPlayer); break;
    }
    dano *= calculaVantagem(tipoPlayer, tipoCPU);
    dano -= defesaCPU;
    if (dano <= 0.0){
        return 0.000000;
    } else {
    return (dano*100000.000000)/100000.000000;; 
    }
}