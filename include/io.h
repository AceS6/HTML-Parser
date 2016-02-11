#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdlib.h>

FILE* openFile(char* path, char* mode);
void closeFile(FILE* f);
#endif
