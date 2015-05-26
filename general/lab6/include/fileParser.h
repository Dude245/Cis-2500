#include <stdio.h>
#ifndef FILE_PARSER_H
#define FILE_PARSER_H


FILE * openFile (char * fileName);

char * readNextLine(FILE * filePointer);

char * getNextToken (char * line);

#endif