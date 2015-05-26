#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int hour,min,second,hour2,min2,second2=0;
printf("First (xx:xx:xx) \n");
scanf("%d:%d:%d",&hour,&min,&second);
printf("Second (xx:xx:xx) \n");
scanf("%d:%d:%d",&hour2,&min2,&second2);
int ah,am,as=0;
if(second2+second>=60)
{
    as=(second2+second)-60;
am++;
}
if(min+min2>=60)
{
    am=(min2+min)-60;
    ah++;
}
ah=hour2+hour;
am=min+min2;
as=second+second2;
printf("Added hours \n");
printf("%d:%d:%d \n",ah,am,as);

}