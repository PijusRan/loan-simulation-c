#ifndef CONFIG_H
#define CONFIG_H

#include "queue.h"

const char* findCFG(int argc, char* argv[]);
void readCFG(const char *filename, queue* Q);
int getRND(int argc, char *argv[]);

#endif