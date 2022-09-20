
#ifndef LCS_READFILE_H
#define LCS_READFILE_H
#include <stdio.h>

#define Errore_file "Errore sul file"
#define Errore_output "Errore di output"

int file_size (FILE *fl);
char *read(FILE *fl);
char *read_file(char *file_I);
void stampa_sol(char *fileOutput,char *sol);
void controllo(FILE *fl, char *errore);

#endif //LCS_READFILE_H
