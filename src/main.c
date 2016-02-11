#include "../include/main.h"
#include "../include/io.h"

int main(){
  printf("HTML parser v0.1\n");
  char* path = "tes";
  char* mode = "r";
  FILE* f =  openFile(path, mode);
  if(f!=NULL){
    printf("successfuly opened file %s\n", path);
    closeFile(f);
    printf("closing file %s\n", path);
  }
  return 0;
}
