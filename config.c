#include "queue.h"
#include "priority_queue.h"
#include "config.h"
#include "loan.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printHelp(const char *command) {
    printf("Naudojimas: %s <skolos.cfg> [parinktys]\n\n", command);
    printf("Argumentai:\n");
    printf("  <skolos.cfg>       Nurodykite failą (privaloma).\n\n");
    printf("Parinktys:\n");
    printf("  -rnd <skaičius>     Reikšmė atsitiktinėms reikšmėms.\n");
    printf("  -h, --help         Parodo pagalbos pranešimą.\n");
}

void readCFG(const char *filename, queue* Q, PQueue* PQ){
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Nepavyko atidaryti failo");
    }

    // Skaitome failą kol pasiekiame pabaigą
    // Tikimės formato: %lf (double) %d (int) %lf (double)
    Loan read;
    while (fscanf(file, "%lf %d %lf %lf", &read.sum, &read.time, &read.interestRate, &read.lateFeeRate) == 4) {
        enqueue(Q, read);
        insert_pq(PQ, read);
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

    fprintf(stderr, "Klaida: Nepavyko rasti .cfg failo parametruose.\n");
    printHelp(argv[0]);
    exit(0);
}