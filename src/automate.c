#include <stdio.h>

#include "../include/automate.h"
#include "../include/stack.h"
#include "../include/io.h"

int i=0;

void run(FILE* f){
      Stack stack;
      State current;  // current state
      char c;         // current analysed caracter
      current = S0;
      while(((c = fgetc(f))!=EOF)){
            switch(current){
                    case S0:
                          if(c=='<'){
                              //printf("chevron ouvrant");
                              current = S1;
                          }
                          else{
                              //printf("error\n");
                          }
                    break;
                    case S1:
                          if(c=='/'){
                              //printf("balise fermante\n");
                              current = S3;
                          }
                          else if(isLetter(c) || isNumber(c)){

                              current = S2;
                          }
                          else{
                              //printf("balise ouvrante\n");
                          }
                    break;
                    case S2:
                          if(c=='>'){
                              current = S6;
                              printf("fin de balise\n");
                          }
                          else if(isLetter(c) || isNumber(c)){
                            i++;
                            printf("is number or letter %d %c\n", i,c);
                          }
                    break;
                    case S3:
                          if(isLetter(c) || isNumber(c)){
                              current = S4;
                          }
                    break;
                    case S4:
                          if(isLetter(c) || isNumber(c)){

                          }
                          else if(c=='>'){
                              current = S5;
                          }
                    break;
                    case S6:
                          // A completer
                    break;
            }
      }
}
