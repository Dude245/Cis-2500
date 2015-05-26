#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
char lineBuffer[100];
FILE *inputFile = NULL;
 long num;
 int i;
 char ** nameArray;

 if (argc != 3) {
   printf ("Usage: please indicate name of input file and the number of entries\n");
   exit(1);
 }
 inputFile = fopen (argv[1], "r");
 num = strtol(argv[2], NULL, 10);
 printf("This is how many names you say are in your file: %ld\n",num);

 nameArray = malloc(sizeof(char*)*num);
 if (inputFile == NULL) {
   printf ( "Error! Could not find input file\n");
   exit(1);
 }
 else {
   for (i=0; i<num; i++){
     fgets (lineBuffer, 100, inputFile);
     printf("Read in the following line %s", lineBuffer);
     nameArray[i]=malloc(sizeof(char)*(strlen(lineBuffer)+1));
     strcpy(nameArray[i], lineBuffer);
   }
   fclose(inputFile);

   for (i=0; i<num; i++){
     if ((strcmp(nameArray[i], "B") >= 0) && (strcmp(nameArray[i], "C")<0)){
       printf("This name starts with a B: %s\n",nameArray[i]);
     }
   }
 }
 return(0);
}

/*str2 = malloc(sizeof(char)*strlen(stringVar)+1); 
  strcpy(str2, stringVar);

char * stringVar;
char * str2;

stringVar = malloc(sizeof(char)*50);
 printf("Enter first word: ");
scanf("%s", stringVar); 
str2 = stringVar;
printf("Enter second word: ");
scanf("%s", stringVar);  
printf("%s\n",str2);  //what is printed?

 char * theString = "A dark and stormy night";
 int len = strlen(theString);
 printf("The length of the string is: %d\n", len);

 int compare = strcmp("Dopey", "Doc");
 printf ("the value of compare is: %d\n", compare);

*/








