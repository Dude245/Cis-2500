/**
* CIS2500 Lab 3 Solution
* Author: Morgan McLaughlin
**/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* getCharAtIndex(char* inputString, int index);

int main(void)
{
  int index;
  char* inputString;
  char* target;
  
  inputString = malloc(sizeof(char)*50);
  
  printf("Enter a string: ");
  scanf("%s", inputString);
  
  printf("You typed: \'%s\'\n", inputString);
  
  printf("Enter an index: ");
  scanf("%d", &index);
  printf("The index entered is: %d\n", index);
  
  target = getCharAtIndex(inputString, index);

  printf("The memory address pointed at by target is: %p\n", target);
  printf("The address of target is: %p\n", &target);
  printf("The character that is pointed at by target is: %c\n", *target);
  
  return 0;
}

/**
* Get the character in inputString at the position specified by index.
* Note we specify position as index -1, as we want the first character to be position 1, rather than 0
**/
char* getCharAtIndex(char* inputString, int index)
{
  char* pointerToChar = &inputString[index - 1];
  
  return (pointerToChar);
}