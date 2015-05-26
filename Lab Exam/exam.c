/*************************filename here.c****************************
Student Name: Nathan Reymer                  Student Number:  0797359
Date: Tuesday Jan 22/13                          Course Name: CIS*2500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
 ****************************************************************************/

#include <stdio.h>
int arrayCalc(int*num);

int main(void) {
    int * pointer;
    int array[25] = {49, 98, 75, 38, 15, 28, 64, 28, 16, 91, 15, 1, 21, 4, 93, 95, 66, 87, 11, 98, 12, 64, 56, 85, 41};
    pointer = &array[0];
    arrayCalc(pointer);
    return 0;
}

int arrayCalc(int*num) {
    int total = 0;
    int i = 0;
    while (i != 25) {
        i++;
        if (i % 2 == 1) {
            total = total + *num;
        }
    }
    printf("Total: %d", total);
    return total;
}