#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

FILE* openFile(char* path, char* mode);
void closeFile(FILE* f);
bool isLetter(char c);
bool isNumber(char c);

#endif
