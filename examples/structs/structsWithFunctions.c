#include <stdlib.h>
#include "student.h"
 
int main(void)
{
struct Student * studentPtr;
studentPtr = malloc(sizeof(struct Student));
loadStudentRecord(studentPtr, "Pebbles", "Flintstone", 12345, 5);
printStudentRecord(studentPtr);
}

