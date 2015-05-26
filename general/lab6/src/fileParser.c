#include <stdlib.h>
#include <string.h>
#include "fileParser.h"


/*this function must take a filename and open the file. It should return NULL if the 
file cannot be opened, possibly printing some polite message to either stdin or stderr */
FILE * openFile (char * fileName){
  FILE * infile=NULL;
      infile = fopen(fileName, "r");
  if (infile == NULL) {
        printf("I couldn't open the file! \n");
        exit(0);
    }
  return(infile);
}

/* this function should return the next line in the file pointed at by file pointer.
it should chop off the hard return ("\n") if there is one before returing the line. The function returns NULL when EOF is reached */
char * readNextLine(FILE * filePointer)
{
     char * line = malloc (sizeof(char) * 100);
     fgets(line, 100, filePointer);
     return (line);
}

/* this function should return the next delimited token in a line
Send it NULL to get second, third and subsequent tokens.   Judi used
commas as delimiters, but you may use any delimiter you like.
*/
char * getNextToken (char * line){

   char * delim = ",";
   return (strtok(line, delim));
}
