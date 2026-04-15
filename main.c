#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "config.h"
#include "loan.h"

// Funkcijos prototipas
int main(int argc, char *argv[]) {
    queue* loanQueue = CreateQueue(10);
    readCFG(findCFG(argc, argv), loanQueue);
    unsigned int randomSeed = getRND(argc, argv);
    
    printf("Random Seed: %d\n\n", randomSeed);
    printf("%s", toStringQueue(loanQueue));

    
    return 0;
}

