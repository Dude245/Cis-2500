#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
char string [100]="";
printf("Enter a string \n");
scanf("%s",&string);
int len=0;
len=strlen(string);
printf("String: %s \n",string);
printf("Reversed string: ");
int x=0;
for(x=len+1;x>=0;x--)
{
    printf("%c",string[x]);
}
printf(" \n");
}