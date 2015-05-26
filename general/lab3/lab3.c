/*************************lab3.c****************************
Student Name: Nathan Reymer                       Student Number:  0797359
Date: Jan 29/13                          Course Name: CIS*2500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
****************************************************************************/

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
char * charnum(char * string, int index);
int main()
{
    char*input;
    int index;
    char *target=NULL;
    input=(char*)malloc(sizeof(char)*50);
    printf("Please enter a string of less than 50 characters \n");
    scanf("%s",input);
    printf("Please enter the character number you would like (integer) \n");
    scanf("%d",&index);
    target=charnum(input,index);
    printf("The memory address is: %p \n",target);
    printf("The address of the target is: %p \n",&target);
    printf("Your chosen character: %c \n",*target);
    return 0;   
}

char * charnum(char * string, int index)
{
    return(&string[index-1]);
    
}
