#include <stdio.h>
#include "algoritmo.h"
#include "readfile.h"


int main(int argc, char *argv[]) {
   if (argc !=4) {
       printf("Devono essere passati 4 argomenti,ne sono stati passati %d.\n",argc);
       printf("Eseguire il comando: ./LCS fileInput1 fileInput2 fileOutput.\n");
       return 0;
   }
    stampa_fileOutput(argv[1], argv[2],argv[3]);
   return 0;
}

