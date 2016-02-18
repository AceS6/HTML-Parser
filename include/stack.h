#ifndef STACK_H
#define STACK_H

#define MAXSIZE 100

#include <stdlib.h>

struct stack{
  unsigned int top;
  char stk[MAXSIZE];
};

typedef struct stack Stack;

Stack* getStack(){
  Stack* stack;
  stack = malloc(sizeof(Stack));
  (*stack).top=0;
  return stack;
}

void deleteStack(Stack* stack){
    free(stack);
}

void push(Stack* stack, char car){
  (*stack).stk[(*stack).top] = car;
  printf("top=%d\n", (*stack).top);
    (*stack).top++;
  //printf("value[%d]=%c\n", (*stack).top-1, (*stack).stk[(*stack).top]-1);
}
char pop(Stack* stack){
  char ret = (*stack).stk[(*stack).top];
  (*stack).top--;
}
void print(Stack* stack){
  printf("printing stack\n");
  for(int i=0;i<(*stack).top;i++){
    printf("[%c]", (*stack).stk[i]);
  }
  printf("\n");
}

#endif
