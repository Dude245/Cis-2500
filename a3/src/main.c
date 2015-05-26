/*************************main.c****************************
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

int main(int argc, char *argv[]) {
    /*Declare all Patron lists for adding*/
    ListHeadPtr ListOne = NULL;
    ListHeadPtr ListTwo = NULL;

    ListHeadPtr snackLine = NULL;
    ListHeadPtr movieLine = NULL;

    ListHeadPtr temp = NULL;
    ListHeadPtr endLine = NULL;
    /*Declare all File data variables*/
    int movieTok, snackTok, timeTok = 0;
    char *idTok = NULL;
    int count = 0;
    idTok = malloc((sizeof (char) *6) + 1);
    char * waitLineOne = NULL;
    char * waitLineTwo = NULL;
    char* MyLine = NULL;
    FILE * inputTwo = NULL;
    FILE *inputFile = NULL;
    FILE *writeFile = NULL;
    /*Define all randomly used variables*/
    int maxTime = 0;
    int minTime = 99999;
    int avgTime = 0;
    int lineOneTime = 0;
    int lineTwoTime = 0;
    int lineThreeTime = 0;
    /*Check to see if program correct*/

    if (argc != 3) {
        printf("Usage: runMe fileNameOne.txt fileNameTwo.txt \n");
        exit(0);
    }
    writeFile = fopen("docs/report.txt", "wt");
    if (writeFile == NULL) {
        printf("I couldn't open the file! \n");
        exit(0);
    }
    inputFile = openFile(argv[1]);
    inputTwo = openFile(argv[2]);
    /*Count the lines in the file, use these values in for loops*/
    int FF = 0;
    int SF = 0;
    char ch;
    do {
        ch = fgetc(inputFile);
        if (ch == '\n') FF++;

    } while (ch != EOF);

    ch = ' ';
    do {
        ch = fgetc(inputTwo);
        if (ch == '\n') SF++;

    } while (ch != EOF);
    /*Go back to the start*/
    rewind(inputFile);
    rewind(inputTwo);
    /*Add entire file to lines*/
    for (count = 0; count <= FF; count++) {
        waitLineOne = readNextLine(inputFile);
        getNextToken(waitLineOne);
        idTok = waitLineOne;
        snackTok = atoi(getNextToken(NULL));
        movieTok = atoi(getNextToken(NULL));
        timeTok = atoi(getNextToken(NULL));
        ListOne = addToBack(ListOne, createPatron(idTok, snackTok, movieTok, timeTok));
    }

    for (count = 0; count <= SF; count++) {
        waitLineTwo = readNextLine(inputTwo);
        getNextToken(waitLineTwo);
        idTok = waitLineTwo;
        snackTok = atoi(getNextToken(NULL));
        movieTok = atoi(getNextToken(NULL));
        timeTok = atoi(getNextToken(NULL));
        ListTwo = addToBack(ListTwo, createPatron(idTok, snackTok, movieTok, timeTok));
    }
    /*Search file for useless people, and kill them.*/
    for (count = 0; count <= (FF); count++) {
        temp = ListOne;
        if (getSnack(getFront(temp)) == 0 && getMovie(getFront(temp)) == 0) {
            ListOne = removeFromFront(ListOne);
        }
        temp = temp->nextPtr;
    }
    for (count = 0; count < (SF); count++) {
        temp = ListTwo;
        if (getSnack(getFront(temp)) == 0 && getMovie(getFront(temp)) == 0) {
            ListTwo = removeFromFront(ListTwo);
        }
        temp = temp->nextPtr;
    }
    /*Display current values*/
    MyLine = (printList(ListOne));
    printf("Wait line 1: \n");
    printf("%s", MyLine);

    MyLine = (printList(ListTwo));
    printf("Wait line 2: \n");
    printf("%s", MyLine);
    printf("\n");

    /*Start sorting people into different lines*/
    /*Check values up to 100000 seconds-*/
    for (count = 0; count < 100000; count++) {
        /*Set temp variable so I don't mess with the list yet*/
        temp = ListOne;
        /*Start sorting people*/
        if (getTime(getFront(temp)) == lineOneTime) {
            lineOneTime = 0;
            if (getMovie(getFront(temp)) == 1 && getSnack(getFront(temp)) == 1) {
                ListOne = removeFromFront(ListOne);
                snackLine = addToBack(snackLine, getFront(temp));
            } else if (getSnack(getFront(temp)) == 1 && getMovie(getFront(temp)) == 0) {
                ListOne = removeFromFront(ListOne);
                snackLine = addToBack(snackLine, getFront(temp));
            } else if (getSnack(getFront(temp)) == 0 && getMovie(getFront(temp)) == 1) {
                ListOne = removeFromFront(ListOne);
                endLine = addToBack(endLine, getFront(temp));
                temp->tTime = getTime(getFront(temp));
            }
        } else {
            lineOneTime++;
        }
        /*Second stream of sorting people*/
        temp = ListTwo;
        if (getTime(getFront(temp)) == lineTwoTime) {
            lineTwoTime = 0;
            if (getMovie(getFront(temp)) == 1 && getSnack(getFront(temp)) == 1) {
                ListTwo = removeFromFront(ListTwo);
                snackLine = addToBack(snackLine, getFront(temp));
            } else if (getSnack(getFront(temp)) == 1 && getMovie(getFront(temp)) == 0) {
                ListTwo = removeFromFront(ListTwo);
                snackLine = addToBack(snackLine, getFront(temp));
            } else if (getSnack(getFront(temp)) == 0 && getMovie(getFront(temp)) == 1) {
                ListTwo = removeFromFront(ListTwo);
                endLine = addToBack(endLine, getFront(temp));
                temp->tTime = getTime(getFront(temp));
            }
        } else {
            lineTwoTime++;
        }
        /*Add the snackLine into the Endline after correct amount of seconds*/
        temp = snackLine;
        if (getTime(getFront(temp)) == lineThreeTime) {
            lineThreeTime = 0;
            if (getMovie(getFront(temp)) == 0) {
                snackLine = removeFromFront(snackLine);

            } else if (getMovie(getFront(temp)) == 1) {
                snackLine = removeFromFront(snackLine);
            }
            /*Should be code here to make it work correctly*/
        }
        if (snackLine != NULL) {
            lineThreeTime++;
        }
    }
    /*Shows people in the SnackLine, stuck forever :( */
    MyLine = (printList(snackLine));
    printf("snackLine(Should be Empty): \n\n");
    printf("%s", MyLine);
    /*Show the patrons who made it through the line*/
    printf("End line: \n");
    printf("%s", printList(endLine));
    printf("\n");
    /*Calculate the average/Max/Min values*/
    temp = endLine;
    for (count = 0; count < length(endLine); count++) {
        avgTime = avgTime + getTime(getFront(temp));
        if (getTime(getFront(temp)) > maxTime) {
            maxTime = getTime(getFront(temp));
        }
        if (getTime(getFront(temp)) < minTime) {
            minTime = getTime(getFront(temp));
        }


        temp = temp->nextPtr;

    }
    avgTime = ((avgTime) / (length(endLine)));
    /*Print out the Max/Min/Avg values*/
    if (maxTime < 10) {
        fprintf(writeFile, "Max:00:00:0%d\n", maxTime);
    } else if (maxTime > 10 && maxTime < 60) {
        fprintf(writeFile, "Max:00:00:%d\n", maxTime);
    } else {
        fprintf(writeFile, "Max:%d\n", maxTime);
    }
    if (minTime < 10) {
        fprintf(writeFile, "Min:00:00:0%d\n", minTime);
    } else if (minTime > 10 && maxTime < 60) {
        fprintf(writeFile, "Min:00:00:%d\n", minTime);
    } else {
        fprintf(writeFile, "Min:%d\n", minTime);
    }
    if (avgTime < 10) {
        fprintf(writeFile, "Avg:00:00:0%d\n", avgTime);
    } else if (avgTime < 60) {
        fprintf(writeFile, "Avg:00:00:%d\n", avgTime);
    } else {
        fprintf(writeFile, "Avg:%d\n", avgTime);
    }


    /*Convert Seconds to hours/min/sec*/
    temp = endLine;
    int convertTime = 0;
    int TimeH = 0;
    int TimeM = 0;
    int TimeS = 0;
    do {
        fprintf(writeFile, "%s:", temp->id);
        convertTime = temp->tTime;
        if (convertTime < 10) {
            fprintf(writeFile, "00:00:0%d\n", convertTime);
        } else if (convertTime < 60) {
            fprintf(writeFile, "00:00:%d\n", convertTime);
        } else if (convertTime > 60) {
            TimeM = convertTime / 60;
            TimeH = convertTime / 3600;
            TimeS = convertTime % 60;
            if (TimeM < 10 && TimeH < 10) {
                fprintf(writeFile, "0%d:0%d:%d\n", TimeH, TimeM, TimeS);
            } else if (TimeH < 10 && TimeM < 10 && TimeS > 10) {
                fprintf(writeFile, "0%d:0%d:%d\n", TimeH, TimeM, TimeS);
            } else if (TimeS < 10) {
                fprintf(writeFile, "%d:%d:0%d\n", TimeH, TimeM, TimeS);
            } else if (TimeM < 10 && TimeH < 10) {
                fprintf(writeFile, "0%d:0%d:%d\n", TimeH, TimeM, TimeS);
            } else if (TimeS < 10) {
                fprintf(writeFile, "0%d:0%d:0%d\n", TimeH, TimeM, TimeS);
            } else if (TimeH < 10) {
                fprintf(writeFile, "0%d:%d:%d\n", TimeH, TimeM, TimeS);
            }

        }

       temp=getNextPatron(temp);
    } while (temp != NULL);
    /*Free ALL THE THINGSs*/
    destroyPatronList(endLine);
    destroyPatronList(movieLine);
    destroyPatronList(snackLine);
    destroyPatronList(ListOne);
    destroyPatronList(ListTwo);
    destroyPatronList(temp);
    fclose(inputFile);
    fclose(inputTwo);
    fclose(writeFile);
    free(temp);
    free(endLine);
    free(ListOne);
    free(ListTwo);
    free(snackLine);
    free(movieLine);
    free(waitLineOne);
    free(waitLineTwo);
    free(MyLine);

    return (0);
}