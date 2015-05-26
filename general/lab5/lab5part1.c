#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{

      FILE *fr;
    fr = fopen("part1.txt", "r");
    if (fr == NULL) {
	printf("I couldn't open the file! \n");
	exit(0);
    }
    char buffer[50];
    while (fgets(buffer, 50, fr)!= NULL)
    {
		printf(" %s ", buffer);
	fgets(buffer, 50, fr);
	printf(" %s ", buffer);
	
	
    }
    printf ("\n");
    fclose(fr);
    return 0;
}