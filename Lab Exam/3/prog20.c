#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
printf("Enter a number <1000 \n");
char num[5]="";
scanf("%s",&num);
if(num[0]=='9')
    printf("Nine Hundred ");
if(num[0]=='8')
    printf("Eight Hundred ");
if(num[0]=='7')
    printf("Seven Hundred ");
if(num[0]=='6')
    printf("Six Hundred ");
if(num[0]=='5')
    printf("Five Hundred ");
if(num[0]=='4')
    printf("Four Hundred ");
if(num[0]=='3')
    printf("Three Hundred ");
if(num[0]=='2')
    printf("Two Hundred ");
if(num[0]=='1')
    printf("One Hundred ");

if(num[1]=='0')
    printf("and ");
if(num[1]=='9')
    printf("Ninety ");
if(num[1]=='8')
    printf("Eighty ");
if(num[1]=='7')
    printf("Seventy ");
if(num[1]=='6')
    printf("Sixty ");
if(num[1]=='5')
    printf("Fifty ");
if(num[1]=='4')
    printf("Fourty ");
if(num[1]=='3')
    printf("Thirty ");
if(num[1]=='2')
    printf("Tweenty ");

if(num[1]=='1'&&num[2]=='1')
{
    printf("and Eleven");
    num[2]=' ';
}
if(num[1]=='1'&&num[2]=='2')
{
    printf("Twelve");
    num[2]=' ';
}
if(num[1]=='1'&&num[2]=='3')
{
    printf("and Thirteen");
    num[2]=' ';
}
if(num[1]=='1'&&num[2]=='4')
{
    printf("and Fourteen");
    num[2]=' ';
}
if(num[1]=='1'&&num[2]=='5')
{
    printf("and Fifteen");
    num[2]=' ';
}
if(num[1]=='1'&&num[2]=='6')
{
    printf("and Sixteen");
    num[2]=' ';
}
if(num[1]=='1'&&num[2]=='7')
{
    printf("and Seventeen");
    num[2]=' ';
}
if(num[1]=='1'&&num[2]=='8')
{
    printf("and eighteen");
    num[2]=' ';
}
if(num[1]=='1'&&num[2]=='9')
{
    printf("and nineteen");
    num[2]=' ';
}
    
    
if(num[2]=='9')
    printf("Nine ");
if(num[2]=='8')
    printf("Eigh ");
if(num[2]=='7')
    printf("Seven ");
if(num[2]=='6')
    printf("Six ");
if(num[2]=='5')
    printf("Five ");
if(num[2]=='4')
    printf("Four ");
if(num[2]=='3')
    printf("Three ");
if(num[2]=='2')
    printf("Two ");
if(num[2]=='1')
    printf("One ");
printf (" \n");

}