#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <stdio.h>
#include "../include/stack.h"
#include "../include/io.h"
typedef enum {
        S0, // starting state
        S1,
        S2,
        S3,
        S4,
        S5,
        S6,
        S7,
        S8,
        S9,
        S10,
        S11,
        S12,
        S13
} State;

void run(FILE* f);
void finishState(FILE* f, Stack* stack);
void freeMemory(Stack* stack);

#endif
