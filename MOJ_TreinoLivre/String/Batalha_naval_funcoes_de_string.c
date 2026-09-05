#include <stdio.h>

int strTamanho(char str[1000]){
    int tam = 0;
    for (tam = 0; tam < 1000; tam++){
        if (str[tam] == '\n' || str[tam] == '\0') break;
    }
    return tam;
}

void strCopia(char str1[1000], char str2[1000]){
    for (int i = 0; i < 1000; i++){
        str1[i] = str2[i];
    }
}

void strConcatena(char str1[1000], char str2[1000]){
    int tam = strTamanho(str1);
    for (int i = tam; i < 1000; i++){
        str1[i] = str2[i - tam];
    }
}

void strAdicionaChar(char str[1000], char c){
    int tam = strTamanho(str);
    str[tam] = c; str[tam+1] = '\0';
}