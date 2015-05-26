#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main ()
{
  int i;
  int num;
  char buffer[100];
  char * myString;
  char ** theStringArray;

printf("How many entries?: ");
scanf("%d", &num);
/*memory for the array of pointers */
theStringArray  = malloc(sizeof(char*)*num);

/*declare memory and strcpy into the actual arrays */

for(i=0; i< num; i++){
  printf("Entry %d: ", i);
  scanf("%s", buffer);
  theStringArray[i] = malloc(sizeof(char)*(strlen(buffer)+1));
  strcpy(theStringArray[i], buffer);
 }

/* let print it to see what we have */
 printf("\n\nHere are the strings you entered into the array\n\n");
 for(i=0; i<num; i++)
   {
     printf("Entry number %d: %s\n", i, theStringArray[i]);
   }
 return(0);
}


