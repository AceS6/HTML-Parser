#include "../include/automate.h"
#include <stdio.h>

void run(FILE* f){

  State current;  // current state
  char c;         // current analysed caracter

  current = Start;
  while(1==1){
    c = fgetc(f);
    switch(current){
            case Start:
            break;
            case S1:
            break;

    }
  }
}
