#ifndef SIMULATIONS_H
#define SIMULATIONS_H

#include "loan.h"
#include "../queue-types/queue.h"
#include "../queue-types/priority_queue.h"

double simulateQueue(queue* loanQueue, unsigned int randomSeed);
double simulatePQueue(PQueue* loanQueue, unsigned int randomSeed);

#endif