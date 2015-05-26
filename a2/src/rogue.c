/*************************rogue.c****************************
Student Name: Nathan Reymer                  Student Number:  0797359
Date: Jan 27/13                         Course Name: CIS*2500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
 ****************************************************************************/

#include "rogue.h"
#include <stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include<string.h>
#include <time.h>
#include <ctype.h>

int main(int argc, char**argv) {
    /*Decleare everything for main*/
    FILE *fr;
    int start;
    int StartX = 3, StartY = 3;
    int move = 0;
    int inputChar;
    int posX, posY;
    char delimit[] = " ";
    char *result = NULL;
    char roomArray[9][150];
    int wcount = 0, health = 100, pcount = 0, acount = 0, tcount = 0;
    int roomnum = 1;
    int len[9];
    int x;
    /*Read file at 2nd argument*/
    fr = fopen(argv[1], "r");
    if (fr == NULL) {
        printf("I couldn't open the file! \n");
        exit(0);
    }
    char buffer[150];
    /*Read buffer, strcopy to an array*/
    while (fgets(buffer, 150, fr) != NULL) {
        acount++;
        strcpy(roomArray[acount], buffer);
        len[acount] = strlen(roomArray[acount]);
    }
    fclose(fr);
    char loopy;
    /*Start my main loop to switch rooms*/
    while (loopy != 'q' && health >= 0) {
        clear();
        /*Give Starting values in case no hero*/
        StartX = 7;
        StartY = 7;
        /* Get the Room Dimensions */
        result = strtok(roomArray[roomnum], "X");
        start = atoi(result);
        StartY = start;
        result = strtok(NULL, delimit);
        start = atoi(result);
        StartX = start;
        result = strtok(NULL, " ");
        /*Look for hero */
        x = 0;
        posY=3;
        posX=3;
        for (x = 0; x < 150; x++) {
            if (result[x] == 'h') {
                posY = result[x + 1];
                posY = posY - 46;
                posX = result[x + 3];
                posX = posX - 46;
            }
        }
                moveMan(posY, posX);
        /*Start my game*/
        initCurses();
        drawRoom(StartX, StartY, roomArray[roomnum], len[roomnum], posY, posX, &wcount, &health, &pcount, &tcount);
        moveMan(posY, posX);
        inputChar = ' ';
        /*Start loop for specific room*/

        while (inputChar != '/' && health >= 0) {
            inputChar = getch();
            clear();
            move = drawRoom(StartX, StartY, roomArray[roomnum], len[roomnum], posY, posX, &wcount, &health, &pcount, &tcount);
            if (move == 1) {
                inputChar = 'n';
            }
            /*Start similar switch statement like tictactoe */
            switch (inputChar) {
                    clear();
                    drawRoom(StartX, StartY, roomArray[roomnum], len[roomnum], posY, posX, &wcount, &health, &pcount, &tcount);
                case 'k':
                {
                    posY = posY - 1;
                    if (posY <= 2) {
                        posY = posY + 1;
                    }
                    drawRoom(StartX, StartY, roomArray[roomnum], len[roomnum], posY, posX, &wcount, &health, &pcount, &tcount);
                    break;
                }
                case 'j':
                {
                    posY = posY + 1;
                    if (posY >= (StartY+1 )) {
                        posY = posY - 1;
                    }
                    drawRoom(StartX, StartY, roomArray[roomnum], len[roomnum], posY, posX, &wcount, &health, &pcount, &tcount);
                    break;
                }
                     
                case 'h':
                {
                    posX = posX - 1;
                    if (posX <= 2) {
                        posX = posX + 1;
                    }
                    drawRoom(StartX, StartY, roomArray[roomnum], len[roomnum], posY, posX, &wcount, &health, &pcount, &tcount);
                    break;
                }
                case 'l':
                {
                    posX = posX + 1;

                    if (posX >= (StartX+1 )) {
                        posX = posX - 1;
                    }
                    drawRoom(StartX, StartY, roomArray[roomnum], len[roomnum], posY, posX, &wcount, &health, &pcount, &tcount);
                    break;
                }
               /*Switch to next room */
                case 'n':
                {

                    if (roomnum > acount - 1) {
                        inputChar = '/';
                        loopy = 'q';
                    } else
                        roomnum++;
                    inputChar = '/';
                    break;
                }
                     /*How to kill the game  */
                case 'q':
                {
                    inputChar = '/';
                    loopy = 'q';
                    break;
                }

                default:
                {
                    drawRoom(StartX, StartY, roomArray[roomnum], len[roomnum], posY, posX, &wcount, &health, &pcount, &tcount);
                    break;
                }

            }
        }
        clear();

    }
    endwin();
    clear();
    /*Print out results*/
    if (health <= 0) {
        printf("Sorry! You died! \n");
    } else {
        printf("Number of weapons: %d \n", wcount);
        printf("Health: %d \n", health);
        printf("Potions: %d \n", pcount);
        printf("Treasure: %d \n", tcount);
        printf("Weapons: %d \n",wcount);
    }
    return 0;
}

