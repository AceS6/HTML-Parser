#ifndef STACK_H
#define STACK_H

#define MAXSIZE 100

struct Stack{
  char stk[MAXSIZE];
  int top;
};

typedef struct Stack Stack;

void push(Stack* stack, char car){
  (*stack).stk[(*stack).top] = car;
  (*stack).top++;
}
char pop(Stack* stack){
  char ret = (*stack).stk[(*stack).top];
  (*stack).top--;
}

#endif
