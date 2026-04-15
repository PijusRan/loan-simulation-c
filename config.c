#include "config.h"
#include "loan.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readCFG(const char *filename, queue* Q){
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Nepavyko atidaryti failo");
    }

    // Skaitome failą kol pasiekiame pabaigą
    // Tikimės formato: %lf (double) %d (int) %lf (double)
    Loan read;
    while (fscanf(file, "%lf %d %lf", &read.sum, &read.time, &read.interest) == 3) {
        enqueue(Q, read);
    }

    fclose(file);
}

int getRND(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        // Tikriname, ar dabartinis argumentas yra "-rnd"
        if (strcmp(argv[i], "-rnd") == 0) {
            // Patikriname, ar po "-rnd" egzistuoja dar vienas argumentas (reikšmė)
            if (i + 1 < argc) {
                return atoi(argv[i + 1]);
            } else {
                fprintf(stderr, "Klaida: Po -rnd parametro nepateikta reikšmė.\n");
                return -1;
            }
        }
    }
    return -1; // Parametras nerastas
}

const char* findCFG(int argc, char* argv[]) {
    for (int i = 1; i < argc; i++) {
        // Tikriname, ar argumento pabaigoje yra ".cfg"
        char* extension = strrchr(argv[i], '.');
        if (extension != NULL && strcmp(extension, ".cfg") == 0) {
            return argv[i];
        }
    }
    return NULL;
}