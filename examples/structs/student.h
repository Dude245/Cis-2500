struct Student
{
  char * firstName;
  char * surname;
  int studentID;
  int GPA;
};

typedef struct Student StudentRec;

int printStudentRecord(struct Student * studentPtr);
int loadStudentRecord(struct Student * studentPtr, char * first, char * last, int id, int gpa);
