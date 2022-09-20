#include "algoritmo.h"
#include "readfile.h"
#include "matrice.h"
#include <stdlib.h>
#include <string.h>

algoritmo *crea_algoritmo(char *string1,char *string2){
    algoritmo *z = (algoritmo*)malloc(sizeof(algoritmo));
    z ->prima_stringa= read_file(string1);
    z ->seconda_stringa= read_file(string2);
    z -> righe= (int) strlen(z->prima_stringa)+1;
    z -> colonne= (int) strlen(z->seconda_stringa)+1;
    z ->valori = (int**) crea_matrice(z->righe,z->colonne);
    z ->tabella = crea_matrice(z->righe, z->colonne);
    return z;
}


int max (int a, int b) {
    if (a>b) {
        return a;
    } else {
        return b;
    }
}

void def_matrice(algoritmo *z){
    for (int a=1; a < z->righe; a++) {
        for (int b=1; b < z->colonne; b++) {
            if(z->prima_stringa[a-1] == z->seconda_stringa[b-1]) { //procedimento all'indietro
                z->valori[a][b] = z->valori[a-1][b-1]+1;// se strignhe uguali
                z->tabella[a][b] = 'd'; //freccia DIAGONALE
            } else {
                z->valori[a][b]= max(z->valori[a-1][b],z->valori[a][b-1]); //se prima stringa diversa dalla seconda
                if(z->valori[a-1][b] >= z->valori[a][b-1]) {
                    z->tabella [a][b] = 't';// freccia ORIZZONTALE
                } else {
                    z->tabella [a][b] ='l'; //freccia VERTICALE
                }
            }
        }
    }
}


void crea_soluzione(algoritmo* z) {
    int a = z->righe-1;
    int b = z-> colonne-1;
    int c = z->valori[a][b];
    z-> risultato = (char*)malloc(sizeof(char)*(c+1));
    z->risultato [c] ='\0';
    while (z->tabella[a][b] !=0) {
        if (z->tabella[a][b] =='d') {
            z->risultato[c-1] = z->prima_stringa[a-1];
            a--;
            b--;
            c--;
        } else if(z->tabella[a][b] == 'l') {
            b--;
        } else if (z->tabella[a][b] == 't') {
            a--;
        }
    }

}

int stampa_fileOutput(char *fileInput1, char *fileInput2, char *fileOutput){
    algoritmo *z = crea_algoritmo(fileInput1,fileInput2);
    if (z->righe== 1 || z->colonne == 1) {
       stampa_sol(fileOutput,"");
    } else if(strcmp(z->prima_stringa, z->seconda_stringa) == 0) {
        stampa_sol(fileOutput,z->prima_stringa);
    } else {
        def_matrice(z);
        crea_soluzione(z);
        stampa_sol(fileOutput,z->risultato);
    }
    svuota_algoritmo(z);
}