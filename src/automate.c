#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#include "../include/automate.h"

bool debugState=false;
bool debugCaracter=true;
bool step=false;

void run(FILE* f){
      Stack* stack =  getStack();
      State current;  // current state

      char c;         // current analysed caracter
      current = S0;
      //char* marker="";
      while(((c = fgetc(f))!=EOF)){
            //printf("\e[1;1H\e[2J");
            //printf(KWHT "\n");
            if(debugCaracter){
                  if(debugState){
                        printf(KWHT "\'%c\'", c);
                  }
                  else{
                        printf(KWHT "%c", c);
                  }

            }
            switch(current){
                    case S0:
                          if(debugState){printf(" STATE S0");}
                          if(c=='<'){
                              printf(KMAG "\n------------ marker");
                              current = S1;
                          }
                          else{
                              //printf("error\n");
                              if(debugState){printf(" (skipping) ");}
                          }
                          printf("\n");
                    break;
                    case S1:
                          if(debugState){printf(" STATE S1\n");}
                          appendToLastTag(stack, c);
                          if(c=='/'){
                              current = S3;
                          }
                          else if(isLetter(c) || isNumber(c)){
                              current = S2;
                          }
                          else{
                                current = S2;
                              //printf("marker ouvrante\n");
                          }
                    break;
                    case S2:
                          if(debugState){printf(" STATE S2\n");}
                          if(c=='>'){
                              //current = S5;
                              printf(KMAG "\n------------ marker\n");
                              finishState(f, stack);
                          }
                          else if(c==' '){
                               printf(KMAG "\n------------ marker");
                               printf(KCYN"\n======= PARAM\n");
                               current = S6;
                          }
                          else{
                                appendToLastTag(stack, c);
                          }
                    break;
                    case S3:
                          if(debugState){printf(" STATE S3\n");}
                          if(isLetter(c) || isNumber(c)){
                              current = S4;
                              appendToLastTag(stack, c);
                          }
                          else if(c=='>'){
                                printf(KMAG "\n------------ marker\n");
                               finishState(f, stack);
                          }
                    break;
                    case S4:
                          if(debugState){printf(" STATE S4\n");}
                          if(c=='>'){
                              //current = S5;
                              printf(KMAG "\n------------ marker\n");
                              finishState(f, stack);
                          }
                          else if(isLetter(c) || isNumber(c)){
                              appendToLastTag(stack, c);
                          }
                          else{
                                //printf("error");
                                appendToLastTag(stack, c);
                          }
                    break;
                    case S5:
                          if(debugState){printf(" STATE S5\n");}
                          printf("\nPress Any Key to Continue\n");
                          getchar();
                          run(f);
                    break;
                    case S6:
                          if(debugState){printf(" STATE S6\n");}
                          if(isLetter(c) || isNumber(c)){
                               current = S7;
                          }
                          else{
                                finishState(f, stack);
                          }
                    break;
                    case S7:
                          if(debugState){printf(" STATE S7\n");}
                          if(c=='='){
                               current = S8;
                          }
                    break;
                    case S8:
                          if(debugState){printf(" STATE S8\n");}
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
                          if(debugState){printf(" STATE S9\n");}
                          if(c==' '){
                              current = S13;
                          }
                    break;
                    case S10:
                          if(debugState){printf(" STATE S10\n");}
                          if(c=='\"'){
                               printf(KCYN "\n======= PARAM\n");
                               current = S12;
                          }
                    break;
                    case S11:
                          if(debugState){printf(" STATE S11\n");}
                          if(c=='\''){
                               printf(KCYN "\n======= PARAM\n");
                               current = S12;
                          }
                    break;
                    case S12:
                          if(debugState){printf(" STATE S12\n");}
                          if(c==' '){
                              current = S6;
                          }
                          else if(c=='>'){
                              //current = S5;
                              finishState(f, stack);
                          }
                    break;
                    case S13:
                          if(debugState){printf(" STATE S13\n");}
                          if(c=='>'){
                              //current = S5;
                              finishState(f, stack);
                          }
                          else if(isLetter(c) || isNumber(c)){
                              current = S7;
                          }
                    break;
            }
      }
      //printf("marker=%s", marker);
      freeMemory(stack);
}

void freeMemory(Stack* stack){
      for(int i=0;i<(*stack).top;i++){
            free((*stack).stk[i]);
      }
      deleteStack(stack);
}

void finishState(FILE* f, Stack* stack){
      printf("\n");
      print(stack);
      push(stack, getTag());
      if(debugState){printf("STATE S5\n");}
      printf(KYEL "\n________________________________________\n");
      if(step){
            printf("\nPress Any Key to Continue\n");
            getchar();
      }
      run(f);
}
