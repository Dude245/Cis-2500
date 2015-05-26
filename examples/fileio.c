#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main (int arc,char * argv[]){
  FILE * infile;
  FILE * outfile;
  FILE * formatfile;
  char buffer[100];
  char  justRead;
  int fileReadReturn;
  int age;
  char * name;
  char * phone;

  
  infile = fopen("testread.txt","r");
  outfile = fopen("testwrite.txt","w");
  formatfile = fopen("formattest.txt", "r");
  if (infile == NULL) {printf ("error opening file\n"); exit(0);}
  if (outfile == NULL) {printf ("error opening file\n"); exit(0);}
  if (formatfile == NULL) {printf ("error opening file\n"); exit(0);}
  fputc('c', outfile);
  fputc('w', outfile);
  fputs("onetwothreefourfive", outfile);

  justRead = fgetc(infile);
     while(justRead != EOF)
     {
     justRead = fgetc(infile);
     printf("%c\n", justRead);
     }


 /*  while(fgets(buffer, 50, infile) != NULL)
    {
      printf("%s\n", buffer);
      fgets(buffer, 50, infile); 
    }*/
name = malloc(sizeof(char)*25);
  phone = malloc (sizeof(char)*15);
  fileReadReturn= fscanf(formatfile,"%d %s %s", &age, name, phone);
  while (fileReadReturn != EOF)
    {
      printf("this is what I read: %d %s %s\n", age, name, phone);
      fileReadReturn= fscanf(formatfile,"%d %s %s", &age, name, phone);
    }

  fclose(infile);
  fclose(outfile);
  fclose(formatfile);
  return(0);
}
/*while (fscanf(in_fd, "%s", username) != EOF)*/
