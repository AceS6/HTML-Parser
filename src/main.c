#include "../include/main.h"
#include "../include/io.h"
#include "../include/automate.h"

int main(){
      printf("HTML parser v0.1\n");
      char* path = "fichier.html";
      char* mode = "r";
      FILE* f =  openFile(path, mode);
      if(f!=NULL){
            printf("successfully opened file %s\n", path);
            run(f);
            closeFile(f);
            printf("closing file %s\n", path);
      }
      return 0;
}
