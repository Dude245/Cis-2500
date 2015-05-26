/*************************linked.c****************************
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

bool isEmpty(ListHeadPtr theList) {
    if (theList == NULL) {
        return (true);
    } else {
        return (false);
    }
}

ListHeadPtr addToFront(ListHeadPtr theList, Patron * toBeAdded) {

    toBeAdded->nextPtr = theList;
    theList = toBeAdded;


    return (theList);


}

ListHeadPtr removeFromFront(ListHeadPtr theList) {
    if (theList != NULL) {
        theList = theList->nextPtr;
    }
    return (theList);
}

Patron * getFront(ListHeadPtr theList) {
  if(theList==NULL)
    {
         return (theList);
    }
    return (theList);
}

ListHeadPtr addToBack(ListHeadPtr theList, Patron * toBeAdded) {
    if (toBeAdded == NULL) {
        theList = theList;

    } else if (theList == NULL) {
        theList = addToFront(theList, toBeAdded);
    } else {
        Patron * backPatron = getBack(theList);
        backPatron->nextPtr = toBeAdded;
        toBeAdded->nextPtr = NULL;
    }
    return (theList);
}

ListHeadPtr removeFromBack(ListHeadPtr theList) {
    Patron *currentPtr = theList;
    Patron *prePtr = NULL;
    if (theList == NULL) {

    } else if (theList->nextPtr == NULL) {
        theList = NULL;
    } else if (theList != NULL) {
        while (currentPtr->nextPtr != NULL) {
            prePtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
        destroyPatron(currentPtr);
        prePtr->nextPtr = NULL;
    }
    return (theList);
}

Patron * getBack(ListHeadPtr theList) {
    Patron *currentPtr = theList;
     if(theList==NULL)
    {
         return (currentPtr);
    }
    while (currentPtr->nextPtr != NULL) {
        currentPtr = currentPtr->nextPtr;
    }
    return (currentPtr);
}

char * printList(ListHeadPtr theList) {
    Patron *tempPtr = theList;
    char * line = NULL;
    line = malloc(sizeof (char) *10000);

    if (theList == NULL) {
        /*Do Nothing*/
    } else if (theList != NULL) {
        do {
            strcat(line, tempPtr->id);
            strcat(line, "\n");

            tempPtr = tempPtr->nextPtr;
        } while (tempPtr != NULL);
    }
    return (line);
}

Patron * createPatron(char * id, bool movie, bool snack, int time) {
    Patron *newPatron = malloc(sizeof (Patron));
    newPatron->id = id;
    newPatron->movie = movie;
    newPatron->snack = snack;
    newPatron->time = time;
    return (newPatron);
}

char * getID(Patron * thePatron)
{
if(thePatron==NULL)
{
    return(NULL);
}
else
    return (thePatron->id);
}

int getTime(Patron * thePatron) {
    if(thePatron==NULL)
{
    return(0);
}
else
    return (thePatron->time);
}

bool getMovie(Patron * thePatron) {
        if(thePatron==NULL)
{
    return(0);
}
        else
    return (thePatron->movie);
}

bool getSnack(Patron * thePatron) {
        if(thePatron==NULL)
{
    return(0);
}
        else
    return (thePatron->snack);
}

void destroyPatron(Patron * thePatron) {
    thePatron->nextPtr = NULL;
    thePatron->id = NULL;
    thePatron->movie = false;
    thePatron->snack = false;
    thePatron->time = 0;
    if (thePatron->nextPtr != NULL) {
        free(thePatron->id);
        free(thePatron);
    }
}

Patron * getNextPatron(Patron * thePatron) {
        if(thePatron==NULL)
{
    return(thePatron);
}
    thePatron = thePatron->nextPtr;
    return (thePatron);
}

int length(ListHeadPtr theList) {
    int length = 0;
    Patron *currentPtr = theList;
    if (theList != NULL) {
        while (currentPtr->nextPtr != NULL) {
            length++;
            currentPtr = currentPtr->nextPtr;
        }
        length++;
    }
    return (length);
}

void destroyPatronList(ListHeadPtr theList) {
    Patron *currentPtr = theList;
    Patron *deadPtr;
    if (theList != NULL) {
        while (currentPtr != NULL) {
            deadPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
            destroyPatron(deadPtr);
            deadPtr->nextPtr = NULL;
        }
    }
}

FILE * openFile(char * fileName) {
    FILE * infile = NULL;
    infile = fopen(fileName, "r");
    if (infile == NULL) {
        printf("I couldn't open the file! \n");
        exit(0);
    }
    return (infile);
}

char * readNextLine(FILE * filePointer) {
    char * line = malloc(sizeof (char) * 20);
    fgets(line, 20, filePointer);
    return (line);
}

char * getNextToken(char * line) {

    char * delim = " ";
    return (strtok(line, delim));
}
