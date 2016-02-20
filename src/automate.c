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

void run(FILE* f){
      Stack* stack =  getStack();
      State current;  // current state

      char c;         // current analysed caracter
      current = S0;
      //char* balise="";
      while(((c = fgetc(f))!=EOF)){
            //printf("\e[1;1H\e[2J");
            //printf(KWHT "\n");
            if(debugCaracter){
                  printf(KWHT "%c", c);
            }
            switch(current){
                    case S0:
                          if(debugState){printf("\nSTATE S0 ");}
                          if(c=='<'){
                              printf(KMAG "\n_______________ balise\n");
                              current = S1;
                          }
                          else{
                              //printf("error\n");
                          }
                    break;
                    case S1:
                          if(debugState){printf("\nSTATE S1 ");}
                          appendToLastTag(stack, c);
                          if(c=='/'){
                              current = S3;
                          }
                          else if(isLetter(c) || isNumber(c)){
                              current = S2;
                          }
                          else{
                                current = S2;
                              //printf("balise ouvrante\n");
                          }
                    break;
                    case S2:
                          if(debugState){printf("\nSTATE S2 ");}
                          if(c=='>'){
                              //current = S5;
                              finishState(f, stack);
                              printf("\nfin de balise\n");
                          }
                          else if(c==' '){
                               printf(KMAG "\n_______________ balise");
                               printf(KCYN"\n======= PARAM\n");
                               current = S6;
                          }
                    break;
                    case S3:
                          if(debugState){printf("\nSTATE S3 ");}
                          if(isLetter(c) || isNumber(c)){
                              current = S4;
                          }
                    break;
                    case S4:
                          if(debugState){printf("\nSTATE S4 ");}
                          if(c=='>'){
                              //current = S5;
                              finishState(f, stack);
                          }
                          else if(isLetter(c) || isNumber(c)){

                          }
                          else{
                                //printf("error");
                          }
                    break;
                    case S5:
                          if(debugState){printf("\nSTATE S5 \n");}
                          printf("\nPress Any Key to Continue\n");
                          getchar();
                          run(f);
                    break;
                    case S6:
                          if(debugState){printf("\nSTATE S6 ");}
                          if(isLetter(c) || isNumber(c)){
                               current = S7;
                          }
                          else{
                                finishState(f, stack);
                                printf("YOLOOOOO");
                          }
                    break;
                    case S7:
                          if(debugState){printf("\nSTATE S7 ");}
                          if(c=='='){
                               current = S8;
                          }
                    break;
                    case S8:
                          if(debugState){printf("\nSTATE S8 ");}
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
                          if(debugState){printf("\nSTATE S9 ");}
                          if(c==' '){
                              current = S13;
                          }
                    break;
                    case S10:
                          if(debugState){printf("\nSTATE S10 ");}
                          if(c=='\"'){
                               printf(KCYN "\n======= PARAM\n");
                               current = S12;
                          }
                    break;
                    case S11:
                          if(debugState){printf("\nSTATE S11 ");}
                          if(c=='\''){
                               printf(KCYN "\n ======= PARAM\n");
                               current = S12;
                          }
                    break;
                    case S12:
                          if(debugState){printf("\nSTATE S12 ");}
                          if(c==' '){
                              current = S6;
                          }
                          else if(c=='>'){
                              //current = S5;
                              finishState(f, stack);
                          }
                    break;
                    case S13:
                          if(debugState){printf("\nSTATE S13 ");}
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
      //printf("balise=%s", balise);
      freeMemory(stack);
}

void freeMemory(Stack* stack){
      for(int i=0;i<(*stack).top;i++){
            free((*stack).stk[i]);
      }
      deleteStack(stack);
}

void finishState(FILE* f, Stack* stack){
      push(stack, getTag());
      if(debugState){printf("STATE S5\n");}
      printf(KYEL "\n_______________________________________________\n");
      printf("\nPress Any Key to Continue\n");
      getchar();
      run(f);
}
