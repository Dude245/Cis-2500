#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (void)
{
char *result = NULL;
int counter=0;
    FILE *fr;
    fr = fopen("part2.txt", "r");
    if (fr == NULL) {
	printf("I couldn't open the file! \n");
	exit(0);
    }
    char buffer[150];
    while (fgets(buffer, 150, fr)!= NULL)
    {
	result = strtok(buffer, ",");
	while(result!=NULL)
	{
	    printf("%s", result);
		result = strtok(NULL, ",");
		printf("\n");
		counter++;
	}

    }
    fclose(fr);
    printf("Counter: %d \n",counter);
    return 0;
}
