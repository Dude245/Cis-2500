/**
* CIS2500 Lab 4 Solution
* Author: Morgan McLaughlin
**/

#include "lab4.h"

char** arrayOfStrings;

int main(int argc, char* argv[])
{
  
  /* Check to make sure we have the correct number of arguements*/
  if (argc != 2)
  {
    printf("Not enough params!\n");
    exit(1);
  }
  
  /*Allocate memory for the string argument*/
  char* tempString = malloc(sizeof(char)*strlen(argv[1]));
  strcpy(tempString, argv[1]);
  
  printf("The string is \'%s\' and its size is %d.\n", tempString, (int)strlen(tempString));
  
  /*Get the number of spaces in our string*/
  int numSpaces;
  numSpaces = getNumSpaces(tempString);
  
  printf("The number of spaces is: %d\n", numSpaces);
  
  /*Allocate enough memory equal to the number of 'words' in our string (sets of characters between spaces)*/
  arrayOfStrings = malloc(sizeof(arrayOfStrings)*numSpaces);
  
  int i, j;
  
  /*A counter for the current character being added to the array*/
  int currentPointerInArray = 0;
  for (i = 0; i <= numSpaces; i++)
  {
    /*Allocate memory for the individual word in our string*/
    /*Note: We could allocate memory for the individual string being added by counting characters until the next
    space, but the lab mentioned to only use 20 and this would require more effort, including another loop.
    Just don't input a string with more than 20 characters between spaces!*/
    arrayOfStrings[i] = malloc(sizeof(char)*20);
    for (j = 0; j < 20; j++)
    {      
      if (tempString[currentPointerInArray] == ' ')
      {
		/*We have reached the end of the string, add a null terminator*/
		arrayOfStrings[i][j] = '\0';
	
		/*Make sure to still increment the counter in order to skip the space*/
		currentPointerInArray++;
		break;
      }
      else
      {
		/*Add the current chracter to our current string*/
		arrayOfStrings[i][j] = tempString[currentPointerInArray];
		currentPointerInArray++;
      }
    }
  }
  
  /*Print out the strings*/
  for (i = 0; i <= numSpaces; i++)
  {
    printf("%s\n", arrayOfStrings[i]);
  }
  
  free(tempString);
  
  exit(0);
}

/**
* Gets the number of spaces contained in stringTest
**/
int getNumSpaces(char* stringTest)
{
  int numSpaces = 0;
  int i;
  
  /*Iterate through each character in the string to look for spaces*/
  for (i = 0; i < strlen(stringTest); i++)
  {
    if (stringTest[i] == ' ')
    {
      /*We've found a space, increment numSpaces*/
      numSpaces++;
    }    
  }
  
  return numSpaces;
}