#include "../include/io.h"

FILE* openFile(char* path, char* mode){
  FILE *f = fopen(path, mode);
  if (f == NULL){
      printf("Error opening file!\n");
      return NULL;
  }
  return f;
}
void closeFile(FILE* f){
    fclose(f);
}
