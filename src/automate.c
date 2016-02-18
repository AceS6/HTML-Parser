#include <stdio.h>

#include "../include/automate.h"
#include "../include/stack.h"
#include "../include/io.h"


void run(FILE* f){
      Stack* stack =  getStack();
      State current;  // current state
      print(stack);
      char c;         // current analysed caracter
      current = S0;
      printf("STATE S0");
      //char* balise="";
      while(((c = fgetc(f))!=EOF) && current != S5){
            printf("\n");
            switch(current){
                    case S0:
                          printf("STATE S0");
                          if(c=='<'){
                              //printf("chevron ouvrant");
                              current = S1;
                          }
                          else{
                              //printf("error\n");
                          }
                    break;
                    case S1:
                          printf("STATE S1");
                          if(c=='/'){
                              //printf("balise fermante\n");
                              current = S3;
                          }
                          else if(isLetter(c) || isNumber(c)){
                              current = S2;
                              //balise+=c;
                              printf("\ncaracter=%c",c);
                          }
                          else{
                              //printf("balise ouvrante\n");
                          }
                    break;
                    case S2:
                          printf("STATE S2");
                          if(c=='>'){
                              current = S5;
                              printf("fin de balise\n");
                          }
                          else if(c==' '){
                            current = S6;
                          }
                          else{
                               //balise+=c;
                               printf("\ncaracter=%c",c);
                          }
                    break;
                    case S3:
                          printf("STATE S3");
                          if(isLetter(c) || isNumber(c)){
                              current = S4;
                          }
                    break;
                    case S4:
                          printf("STATE S4");
                          if(c=='>'){
                              current = S5;
                          }
                    break;
                    case S5:
                          printf("STATE S5");
                          printf("automate finished");
                    break;
                    case S6:
                          printf("STATE S6");
                          if(isLetter(c) || isNumber(c)){
                              current = S7;
                          }
                    break;
                    case S7:
                          printf("STATE S7");
                          if(c=='='){
                              current = S8;
                          }
                    break;
                    case S8:
                          printf("STATE S8");
                          if(c=='\"'){
                              current = S10;
                          }
                          else if(c=='\''){
                              current = S11;
                          }
                          else if(isLetter(c) || isNumber(c)){
                              current = S9;
                          }
                    break;
                    case S9:
                          printf("STATE S9");
                          if(c==' '){
                              current = S13;
                          }
                    break;
                    case S10:
                          printf("STATE S10");
                          if(c=='\"'){
                              current = S12;
                          }
                    break;
                    case S11:
                          printf("STATE S11");
                          if(c=='\''){
                              current = S12;
                          }
                    break;
                    case S12:
                          printf("STATE S12");
                          if(c==' '){
                              current = S6;
                          }
                          else if(c=='>'){
                              current = S5;
                          }
                    break;
                    case S13:
                          printf("STATE S13");
                          if(c=='>'){
                              current = S5;
                          }
                          else if(isLetter(c) || isNumber(c)){
                              current = S7;
                          }
                    break;
            }
      }
      //printf("balise=%s", balise);
      deleteStack(stack);
}
