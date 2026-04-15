#ifndef CONFIG_H
#define CONFIG_H

#include "queue.h"

void readCFG(const char *filename, queue* Q);
int getRND(int argc, char *argv[]);

#endif