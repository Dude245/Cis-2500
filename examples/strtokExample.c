#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main (int argc, char * argv[]){
  char * theString;
  char* theToken;

  if (argc != 2)
    { 
      printf("usage: enter a quoted string");
      exit(1);
    }
  theString = malloc((sizeof(char)*sizeof(argv[1])+1));
  strcpy(theString, argv[1]);
  printf("%s\n", theString);
  theToken = strtok(theString, " ");
  printf("%s\n", theToken);
  printf("%s\n", theString);



}
