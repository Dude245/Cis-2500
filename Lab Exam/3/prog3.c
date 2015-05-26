#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("Enter a the first string: \n");
    char s1[100]="";
    scanf("%s",&s1);
    printf("Enter the second string: \n");
    char s2[100]="";
    scanf("%s",&s2);
    
    printf("S1: %s S2: %s",s1,s2);
    int x=0;
    int y=0;
    int len=0;
    len=strlen(s1);
    int m=0;
    int t=0;
    for(x=0;x<100;x++)
    {
	if (s1[x]==s2[x])
	{
	   m++;
	}
	if(m==len)
	    t=1;
    }
        printf (" \n");
    if(t=1)
	printf("Its a subsrtring");
    else
	printf("Not a substring");
    printf (" \n");
}