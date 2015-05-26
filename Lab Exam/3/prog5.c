#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
printf("Enter a string: \n");
char string[100]="";
scanf("%s",&string);
int x=0;
int y=0;
int len=0;
len=(strlen(string)+1);
for(x=0;x<len;x++)
{
y++;
    printf("%c",string[x]);
    if(y==4)
    {
	printf(" \n");
	y=0;
    }
        if(y==3&&x==len-2)
    {
	printf("0");
	y=0;
    }
    if(y==2&&x==len-2)
    {
	printf("00");
	y=0;
    }
    if(y==1&&x==len-2)
    {
	printf("000");
	y=0;
    }
    
  
}
printf (" \n");
}