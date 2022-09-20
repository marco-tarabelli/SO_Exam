
#ifndef LCS_ALGORITMO_H
#define LCS_ALGORITMO_H

struct algoritmo {
    char* prima_stringa;
    char* seconda_stringa;
    int righe;
    int colonne;
    char *risultato;
    char** tabella;
    int** valori;
};
typedef struct algoritmo algoritmo;

algoritmo *crea_algoritmo(char *string1, char *string2);
int max(int a, int b);
void def_matrice(algoritmo *z);
void crea_soluzione(algoritmo *z);
int stampa_fileOutput(char *fileInput1, char *fileInput2, char *fileOutput);
#endif //LCS_ALGORITMO_H
