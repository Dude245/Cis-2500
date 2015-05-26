#include <stdio.h>
#include <stdlib.h>

int main ()
{
  /* Allocating memory with malloc puts memory on the heap.  Declaring a variable allocates memory on the stack */
  int i, j;
  int * k;
  int * n;

   k = malloc(sizeof(int));
  if(k==NULL) {  printf("Out of memory\n");  exit(0);}
  
 


  i = 1;
  j=5;
  *k=4;  /*dereferencing the pointer to put a value in the allocated memory */
 
 

 printf("the value of i: %d\n", i);
 printf("the value of j: %d\n", j);
  /*look at the addresses when this runs. */

  printf("the address of i (static): %p\n",&i);
  printf("the address of j (static): %p\n\n", &j);

printf("the value pointed at by k (pointer): %d\n", *k);
printf("the address held by k (dynamic): %p\n",k);
printf("the address of k (pointer): %p\n\n", &k);
 

 /*point n at i */
 n = &i;
printf("the value pointed at by n (pointer): %d\n", *n);
printf("the address held by n (pointing at static): %p\n", n);
printf("the address of n (pointer): %p\n\n", &n);

/*point n at j */

 n = &j;
printf("the value pointed at by n (pointer): %d\n", *n);
printf("the address held by n (pointing at static): %p\n", n);
printf("the address of n (pointer): %p\n", &n);


  return 0;
}

