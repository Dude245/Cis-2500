#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main ()
{
  int myInt;
  int * dynArray;
  int i;
  char * myString;
  int w;

srand ( time(NULL) );
printf("Enter an integer number: ");
scanf("%d", &myInt);
dynArray = malloc(sizeof(int)*myInt);


 for(i=0; i<=myInt; i++){
   dynArray[i] = rand()%100;
 }
 
 for(i=0; i< myInt; i++){
   printf("%d, ", dynArray[i]);
 }
 printf("\n");



}


 /* myString = malloc(sizeof(char)*myInt);
 printf("Enter a string of less than %d characters: ", myInt);
  scanf("%s", myString);
printf("here is your string: %s\n", myString);
 for(i=0; i< myInt; i++){
   printf("%c\n", myString[i]);
 }
 printf("\n");*/

/*
  printf("\n");

*/
