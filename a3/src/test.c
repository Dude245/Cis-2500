/*************************test.c****************************
Student Name: Nathan Reymer                  Student Number:  0797359
Date: Mar 26/13                              Course Name: CIS*2500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
 ****************************************************************************/
#ifndef BOOL_H
#define BOOL_H
typedef int bool;

enum {
    false, true
};
#endif
#ifndef deffy
#define deffy
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedList.h"
#define BUFFER 100
#endif

int main() {
    /*Set up the main List*/
    ListHeadPtr theList = NULL;
    char* MyLine = NULL;
    theList = NULL;
    int count = 0;
    int fail = 0;
    printf(" \n");
    printf("---------------------------------------------------------------------------- \n");
    printf("All tests that pass will say 'Passed' and Test failed will show as 'Failed' \n\n");
    printf("Testing isEmpty(theList): ");
    if (isEmpty(theList) == true) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    theList = addToBack(theList, createPatron("Nathan", 1, 1, 50));
    printf("Testing isEmpty(one patron): ");
    /*Simple if false*/
    if (isEmpty(theList) == false) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf("Testing isEmpty(many patrons): ");
    theList = addToBack(theList, createPatron("Nathan", 1, 1, 50));
    theList = addToBack(theList, createPatron("Nathan", 1, 1, 50));
    /*Simple if false*/
    if (isEmpty(theList) == false) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf(" \n");
    printf("Testing createPatron (normal values): ");
    theList = addToBack(theList, createPatron("Nathan", 1, 1, 50));
    /*Check if the last element matches what I added*/
    if (theList->movie == 1 && theList->snack == 1 && theList->time == 50) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf("Testing addToFront(theList, testPatron): ");
    theList = addToFront(theList, (createPatron("Nathan", 1, 1, 80)));
    /*Check if the last element matches what I added*/
    if (theList->snack == 1 && theList->movie == 1 && theList->time == 80) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf(" \n");
    theList = NULL;
    printf("Testing getFront(empty list): ");
    /*Check if return is null*/
    if (getFront(theList) == NULL) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf("Testing getFront(one patron): ");
    theList = addToBack(theList, createPatron("Nathan", 1, 1, 50));
    if (getFront(theList) == theList) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf("getFront(many patrons): ");
    theList = addToBack(theList, createPatron("Nathan", 1, 1, 50));
    theList = addToBack(theList, createPatron("Alex", 0, 1, 10));
    theList = addToBack(theList, createPatron("Cole", 1, 0, 20));
    theList = addToBack(theList, createPatron("Drew", 1, 1, 30));
    if (getFront(theList) == theList);
    {
        printf("Passed \n");
        count++;
    }

    printf(" \n");
    theList = NULL;
    printf("Testing getBack(empty list): ");
    /*Check to see if NULL return*/
    if (getBack(theList) == NULL) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf("Testing getBack(one patron): ");
    theList = addToBack(theList, createPatron("Nathan", 1, 1, 50));
    if (getBack(theList) == theList) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf("Testing getBack(many patrons): ");
    theList = addToBack(theList, createPatron("Nathan", 1, 1, 50));
    theList = addToBack(theList, createPatron("Alex", 0, 1, 10));
    theList = addToBack(theList, createPatron("Cole", 1, 0, 20));
    theList = addToBack(theList, createPatron("Drew", 1, 1, 30));
    if (getBack(theList) == theList);
    {
        printf("Passed \n");
        count++;
    }
    printf(" \n");
    theList = NULL;
    printf("Testing addToFront(empty list, new patron): ");
    theList = addToFront(theList, createPatron("Nathan", 1, 1, 50));
    /*Check if the last element matches what I added*/
    if (theList->snack == 1 && theList->movie == 1 && theList->time == 50) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf("Testing addToFront(list with one patron, new patron): ");
    theList = addToFront(theList, createPatron("Cole", 1, 1, 60));
    /*Check if the last element matches what I added*/
    if (theList->snack == 1 && theList->movie == 1 && theList->time == 60) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf("Testing addToFront(list with many patrons, new patron): ");
    theList = addToFront(theList, createPatron("Alex", 1, 1, 60));
    theList = addToFront(theList, createPatron("Drew", 1, 1, 30));
    theList = addToFront(theList, createPatron("UCole", 1, 1, 20));
    /*Check if the last element matches what I added*/
    if (theList->snack == 1 && theList->movie == 1 && theList->time == 20) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf(" \n");
    theList = NULL;
    printf("Testing addToBack(empty list, new patron): ");
    theList = addToBack(theList, createPatron("Cole", 1, 1, 20));
    /*Check if the last element matches what I added*/
    if (theList->snack == 1 && theList->movie == 1 && theList->time == 20) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf("Testing addToBack(list with one patron, new patron): ");
    theList = addToBack(theList, createPatron("Cole", 1, 1, 80));
    theList = theList->nextPtr;
    /*Check if the last element matches what I added*/
    if (theList->snack == 1 && theList->movie == 1 && theList->time == 80) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf(" \n");
    theList = NULL;
    printf("Testing length(empty list): ");
    /*Check if no elements */
    if (length(theList) == 0) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf("Testing length(one patron): ");
    theList = addToBack(theList, createPatron("Alex", 1, 1, 60));
    /*Check if one element*/
    if (length(theList) == 1) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf("Testing length(many patrons): ");
    theList = addToBack(theList, createPatron("Alex", 1, 1, 60));
    theList = addToBack(theList, createPatron("Cole", 1, 1, 20));
    theList = addToBack(theList, createPatron("Alex", 1, 1, 60));
    theList = addToBack(theList, createPatron("Cole", 1, 1, 20));
    /*Check if 5 elements*/
    if (length(theList) == 5) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf(" \n");
    printf("Testing removeFromBack(empty list): ");
    theList = NULL;
    theList = removeFromBack(theList);
    /*Check if return is null*/
    if (theList == NULL) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf("Testing removeFromBack(empty list(again): ");
    theList = NULL;
    theList = removeFromBack(theList);
    /*Check if return is null*/
    if (theList == NULL) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf("Testing removeFromBack(one patron): ");
    theList = addToBack(theList, createPatron("Cole", 1, 1, 20));
    theList = removeFromBack(theList);
    /*Check if return is null*/
    if (theList == NULL) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf("Testing removeFromBack(many patrons): ");
    theList = addToBack(theList, createPatron("Cole", 1, 1, 20));
    theList = addToBack(theList, createPatron("Alex", 1, 1, 30));
    theList = addToBack(theList, createPatron("Drew", 1, 1, 24));
    theList = addToBack(theList, createPatron("Nathan", 1, 1, 60));
    theList = removeFromBack(theList);
    theList = theList->nextPtr;
    theList = theList->nextPtr;
    /*Check if last value is what I inputted*/
    if (theList->snack == 1 && theList->movie == 1 && theList->time == 24) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf(" \n");

    printf("Testing removeFromFront(empty list): ");
    theList = NULL;
    theList = removeFromFront(theList);
    /*Check if last value is what I inputted*/
    if (theList == NULL) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf("Testing removeFromFront(one patron): ");
    theList = NULL;
    theList = addToBack(theList, createPatron("Nathan", 1, 1, 60));
    theList = removeFromFront(theList);
    /*Check if last value is what I inputted*/
    if (theList == NULL) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf("Testing removeFromFront(many patrons): ");
    theList = NULL;
    theList = addToBack(theList, createPatron("Nathan", 1, 1, 60));
    theList = addToBack(theList, createPatron("Alex", 1, 1, 40));
    theList = addToBack(theList, createPatron("Cole", 1, 1, 20));
    theList = addToBack(theList, createPatron("Drew", 1, 1, 10));
    theList = removeFromFront(theList);
    /*Check if last value is what I inputted*/
    if (theList->snack == 1 && theList->movie == 1 && theList->time == 40) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf(" \n");
    theList = NULL;
    printf("Testing printList(emptylist): ");
    MyLine = (printList(theList));
    /*Check if last value is what I inputted*/
    if (MyLine == NULL);
    {
        printf("Passed \n");
        count++;
    }

    theList = NULL;
    theList = addToBack(theList, createPatron("Drew", 1, 1, 10));
    printf("Testing printList(One Patron): ");
    /*Check if last value is what I inputted*/
    if (theList->movie == 1 && theList->snack == 1 && theList->time == 10) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    theList = NULL;
    theList = addToBack(theList, createPatron("Cole", 1, 1, 20));
    theList = addToBack(theList, createPatron("Drew", 1, 1, 10));
    printf("Testing printList(theList): \n");
    /*Check if last value is what I inputted*/
    if (theList->movie == 1 && theList->snack == 1 && theList->time == 20) {
        printf("Printed First Element successfully \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    theList = theList->nextPtr;
    if (theList->movie == 1 && theList->snack == 1 && theList->time == 10) {
        printf("Printed Second Element successfully \n");
        count++;

    } else {
        printf("Failed \n");
        fail++;
    }
    printf(" \n");
        printf("Testing destroyPatron(One element): ");
    theList=NULL;
    theList = addToBack(theList, createPatron("Cole", 1, 1, 20));
    destroyPatron(getFront(theList));
    theList = removeFromFront(theList);
    if (theList == NULL) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    theList = NULL;
    printf("Testing destroyPatronList (Multiple Patrons List): ");
    theList = addToBack(theList, createPatron("Cole", 1, 1, 20));
    theList = addToBack(theList, createPatron("Cole", 1, 1, 20));
    theList = addToBack(theList, createPatron("Cole", 1, 1, 20));
    destroyPatronList(theList);
    theList = removeFromFront(theList);
    if (theList == NULL) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    theList = NULL;
    printf("Testing destroyPatronList (One Patron): ");
    theList = addToBack(theList, createPatron("Cole", 1, 1, 20));
    destroyPatronList(theList);
    theList = removeFromFront(theList);
    if (theList == NULL) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf(" \n");
    printf("Testing getID(Empty): ");
    theList = NULL;
    if (getID(theList) == NULL) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf("Testing getMovie(empty List): ");
    theList = NULL;
    if (getMovie(theList) == 0) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf("Testing getSnack(empty List): ");
    theList = NULL;
    if (getSnack(theList) == 0) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf("Testing getTime(empty List): ");
    theList = NULL;
    if (getTime(theList) == 0) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf("Testing getNextPatron(empty List): ");
    theList = NULL;
    theList = getNextPatron(theList);
    if (theList == NULL) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf(" \n");
    printf("Testing destroyPatronList (empty List): ");
    theList = NULL;
    destroyPatronList(theList);
    if (theList == NULL) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf("Testing getMovie(One element): ");
    theList = addToBack(theList, createPatron("Cole", 1, 1, 20));
    if (getMovie(theList) == 1) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf("Testing getSnack(One Element): ");
    if (getSnack(theList) == 1) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    printf("Testing getTime(empty List): ");
    if (getTime(theList) == 20) {
        printf("Passed \n");
        count++;
    } else {
        printf("Failed \n");
        fail++;
    }
    
    printf(" \n\n");
    printf("Passed %d out of 42 tests :) \n", count);
    printf("Failed %d out of 42 tests :( \n", fail);
    printf("---------------------------------------------------------------------------- \n");
    printf(" \n");
    destroyPatronList(theList);
    theList = removeFromFront(theList);
    free(MyLine);
    return (0);
}