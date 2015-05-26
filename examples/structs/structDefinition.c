#include <stdio.h>
#include<stdlib.h>
/*structure definition- does not allocate any variables */
   struct Date
   {
       int day;
       int month;
       int year;
   };

int main(void)
{

/*structure allocation- static (because there is no malloc) */
  struct Date birthday;
  birthday.day = 15;
  birthday.month = 11;
  birthday.year = 1800;
  printf("Your birthday is the \%d day of the \%d month in \%d\n", birthday.day, birthday.month, birthday.year);
  return(0);
  }
