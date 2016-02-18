#include "../include/io.h"

FILE* openFile(char* path, char* mode){
      FILE *f = fopen(path, mode);
      if (f == NULL){
            printf("Failed to open file %s\n", path);
            return NULL;
      }
      return f;
}
void closeFile(FILE* f){
      fclose(f);
}
bool isLetter(char c){
      if((c > 'a' && c < 'z') || (c > 'A' && c < 'Z')){
            return true;
      }
      return false;
}
bool isNumber(char c){
      if(c > '0' && c < '9'){
            return true;
      }
      return false;
}
