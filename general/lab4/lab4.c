#include "lab4.h"
int main (int argc, char * argv[])
{
    char ** Array;
    
    if (argc ==1)
    { 
	printf("Put in more arguments! \n");
	exit(1);
    }
    char * myString;
    int numSpace;
    myString=(char*)malloc(sizeof(char)*(strlen(argv[1])));
    strcpy(myString, argv[1]);
    numSpace=myFun(myString);
    printf("My string: %s \n",myString);
    int len;
    len=(strlen(myString));
    printf("String length: %d \n",len);
    printf("Number of spaces: %d \n",numSpace);
    
    Array=(char**)malloc(sizeof(char)*(len));
    int x=0;
    for(x=0;x<len;x++)
    {
	Array[x]=(char*)malloc(sizeof(char)*20);
    }
    int i=0;
    int j=0;
    for(i=0;i<len;i++)
    {
	for(j=0;j<len;j++)
	{
	    Array[i][j]=myString[i];
	    if (myString[i]==' ')
	    {
		Array[i][j]='\0';
	    }
	    printf("%c",Array[i][j]);
	    if (myString[i]==' ')
	    {
		printf(" \n");
	    }
	    break;
	}
	
    }
    printf(" \n");
    
    free(myString);
    return 0;
}
int myFun(char* string)
{
    
    int numSpace=0;
    int i=0;
    for(i=0;i<(strlen(string));i++)
    {
	if (string[i]==' ')
	{
	    numSpace++;
	}
    }
    return(numSpace);
}