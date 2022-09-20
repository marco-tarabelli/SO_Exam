#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "readfile.h"

int file_size (FILE *fl) {
    fseek(fl,0,SEEK_END);
    int size = ftell(fl);
    rewind(fl);
    return size;
}

char *read(FILE *fl) {
    char *buff = (char*) malloc(sizeof(char)*(file_size(fl)+1));
    int a = 0;
    char b;
    while ((b=(char) toupper(fgetc(fl))) !=EOF) {
        buff[a] = b;
        a++;
    }
    buff[a] = '\0';
    return buff;
}


char *read_file(char *file_I) {
    FILE *fl = fopen(file_I, "r");
    char *buff = read(fl);
    controllo(fl,Errore_file);
    fflush(fl);
    fclose(fl);
    return buff;
}


void stampa_sol(char *fileOutput, char *sol){
    FILE *fl = fopen(fileOutput,"w");
    controllo(fl,Errore_output);
    fprintf(fl,"%s", sol);
    printf("algoritmo eseguito con successo:\n");
    printf("stringa comune -----> %s\n",sol);
    fclose(fl);
}

void controllo(FILE *fl, char *errore){
    if (fl == NULL) {
        printf("%s\n",errore);
        exit (0);
    }
}





