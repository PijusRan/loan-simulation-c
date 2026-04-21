#ifndef CONFIG_H
#define CONFIG_H

#include "../queue-types/queue.h"
#include "../queue-types/priority_queue.h"
#include "config.h"
#include "loan.h"

const char* findCFG(int argc, char* argv[]);
void readCFG(const char *filename, queue* Q, PQueue* PQ);
int getRND(int argc, char *argv[]);
void printHelp(const char *command);


#endif