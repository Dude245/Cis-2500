/*************************labExamTwo.c****************************
Student Name: Nathan Reymer                  Student Number:  0797359
Date: Feb 12/13                          Course Name: CIS2500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
****************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/* put your function prototype here*/
int myfun(char * fstring);



/* Main should go here */
int main(void){
    char buffer[100];
    int length;
    int times=0;
    printf("Enter a string up to 100 characters long: \n");
    gets(buffer);
    char * string;
    length=strlen(buffer);
    string=malloc(sizeof(char)*(length));
    strcpy(string,buffer);
    times=myfun(string);
    
    return(0);
}

/*define your function here */
int myfun(char * fstring)
{
    int num=0;
    int length;
    int round=0;
    int rround=0;
    length=strlen(fstring);
    round=length/4;
    if(length % 4 !=0)
	round++;
    
    while (rround!=round)
    {
	printf("%d ",rround+1);
	printf("%c",fstring[num]);
	printf("%c",fstring[num+1]);
	printf("%c",fstring[num+2]);
	printf("%c",fstring[num+3]);
	printf (" \n");
	rround++;
	num+=4;
	
    }
    return(rround);
}