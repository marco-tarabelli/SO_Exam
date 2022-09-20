#include "matrice.h"

#include <stdlib.h>

char **crea_matrice (int righe, int colonne){
    char **matrice = (char**) malloc(sizeof(char*)* righe);
    for (int a=0; a < righe; a++) {
        matrice [a] = (char*) calloc (colonne, sizeof(char*));
    }
    return matrice;
}

void svuota_matrice(char **matrice_c,int **matrice_i, int righe){
    if (matrice_c !=NULL && matrice_i !=NULL){
        for(int a=0; a<righe; a++) {
            free(matrice_c[a]);
            matrice_c[a] = NULL;
            free(matrice_i[a]);
            matrice_i[a] = NULL;
        }
        free(matrice_i); // matrice VALORI
        free(matrice_c); // matrice TABELLA
        matrice_i = NULL;
        matrice_c = NULL;
    }
}



void svuota_algoritmo(algoritmo *z){
    free(z->prima_stringa);
    z->prima_stringa = NULL;
    free(z->seconda_stringa);
    z->seconda_stringa = NULL;
    if(z->risultato !=NULL) {
        free(z->risultato);
        z->risultato = NULL;
    }
    svuota_matrice(z->tabella,z->valori,z->righe);
    free(z);
}