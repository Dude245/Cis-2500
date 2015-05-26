#include <stdio.h>
void mySwap (int*, int*);
void printArray(int *);

int main(void) 
{
  int arrayForSorting[10] = {56,34, 2,98, 23, 59};
  int * arrayPtr = arrayForSorting;
  int i, j; /*loop counter */
  int * biggestNum;
  for(i=0; i<6; i++)
    {
      biggestNum = &arrayForSorting[i];
      for(j=i; j<6; j++) 
	{ 
	  if (arrayForSorting[j] > *biggestNum){
	    biggestNum = &arrayForSorting[j];
	  }
	}
      if (biggestNum != &arrayForSorting[i]){
	mySwap(biggestNum, &arrayForSorting[i]); }  
    }
  printArray(arrayPtr);
  return(0);	
}

void printArray( int * array)
{
  int k;
  for (k=1; k < 6; k++)
    {
      printf("%d ", array[k]);
    }
  printf("\n");
}

void mySwap (int * p, int * r)
{
  int swapSpace;
  swapSpace = * p;
  *p = *r;
  *r = swapSpace;
}
