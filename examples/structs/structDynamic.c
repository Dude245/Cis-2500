#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*structure definition-no allocation happening here */
struct Student
{
  char * firstName;
  char * surname;
  int studentID;
  int GPA;
};

int main(void)
{
int bufSize = 50;

 /*structure allocation- static */
 struct Student myFirstStudent;
 myFirstStudent.firstName = malloc(sizeof(char)*bufSize);
 myFirstStudent.surname = malloc(sizeof(char)*bufSize);
 strcpy(myFirstStudent.firstName, "Pebbles");
 strcpy(myFirstStudent.surname, "Flintstone");
 
 /*structure allocation- dynamic */
 struct Student * mySecondStudentPtr;
 mySecondStudentPtr = malloc(sizeof(struct Student));
 mySecondStudentPtr->firstName = malloc(sizeof(char)*bufSize);
 mySecondStudentPtr->surname = malloc(sizeof(char)*bufSize);
 strcpy(mySecondStudentPtr->firstName, "Bam Bam");
 strcpy(mySecondStudentPtr->surname, "Rubble");

 /*printing */
 printf("The first student is: %s %s\n", myFirstStudent.firstName, myFirstStudent.surname);
 printf("The second student is: %s %s\n", mySecondStudentPtr->firstName, mySecondStudentPtr->surname);
 return(0);
 }
