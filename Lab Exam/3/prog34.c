#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("Enter a 3 digit number: \n");
    char string[4]="";
    char temp;
    scanf("%s",&string);
      printf (" \n");
    printf("%c%c%c \n",string[0],string[1],string[2]);
    printf("%c%c%c \n",string[2],string[1],string[0]);
    
    printf("%c%c%c \n",string[1],string[0],string[2]);
    printf("%c%c%c \n",string[0],string[2],string[1]);
    
    printf("%c%c%c \n",string[1],string[2],string[0]);
    printf("%c%c%c \n",string[2],string[0],string[1]);
    
    
    
    printf (" \n");
}