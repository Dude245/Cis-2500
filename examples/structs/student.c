#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "student.h"

int printStudentRecord(StudentRec * studentPtr)
 {
  printf ("%s, %s (%d): %d\n", studentPtr->surname, studentPtr->firstName, studentPtr->studentID, studentPtr->GPA);
  }
  
int loadStudentRecord(StudentRec * studentPtr, char * first, char * last, int id, int gpa)
{
 studentPtr->firstName = malloc(sizeof(char)*(strlen(first)+1));
 studentPtr->surname = malloc(sizeof(char)*(strlen(last)+1));
 strcpy(studentPtr->firstName, first);
 strcpy(studentPtr->surname, last);
 studentPtr->studentID = id;
 studentPtr->GPA = gpa;
 }
