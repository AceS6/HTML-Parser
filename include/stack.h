#ifndef STACK_H
#define STACK_H

#define MAXSIZE 100

#include <stdio.h>
#include "../include/tag.h"

struct stack{
      unsigned int top;
      Tag* stk[MAXSIZE];
};

typedef struct stack Stack;

Stack* getStack();

Tag* top(Stack* stack);

void appendToLastTag(Stack* stack, char car);

void deleteStack(Stack* stack);

void push(Stack* stack, Tag* car);

Tag* pop(Stack* stack);

void print(Stack* stack);

#endif
