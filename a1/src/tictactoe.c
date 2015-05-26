/*************************filename here.c****************************
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

#include "tictactoe.h"
#include <stdio.h>
#include<stdlib.h>

int main() {
    /*Declare all my variables*/
    int inputChar;
    int myposy;
    int myposx;
    int a = 0;
    int winner;
    int player = 0;
    int *winn;
    char * board;
    int * px;
    int * pp;
    int * py;
    px = &myposx;
    pp = &player;
    py = &myposy;
    char boardData[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    board = &boardData[0];
    winn = &winner;
    initCurses();
    drawBoard();
    myposy = 4;
    myposx = 7;
    /*Put down empty board*/
    moveCursor(myposy, myposx);
    drawPieces(boardData);
    moveCursor(myposy, myposx);
    player = player % 2;
    mvwprintw(stdscr, 20, 0, "Player: %d", player + 1);
    /*Start playing the game*/
    while (inputChar == inputChar) {
        /*Reset winning counter*/
        winner = 0;
        while (inputChar != 'q') {
            inputChar = getch();
            /*Draw modified values for cursor and board*/
            moveCursor(myposy, myposx);
            clear();
            drawBoard();
            refresh();
            drawPieces(boardData);
            switch (inputChar) {
                case KEY_UP:
                {
                    myposy = myposy - 3;
                    if (myposy <= 1) {
                        mvwprintw(stdscr, 19, 0, "Out of bounds \n");
                        myposy = myposy + 3;
                    }
                    moveCursor(myposy, myposx);
                    break;
                }
                case KEY_DOWN:
                {
                    myposy = myposy + 3;
                    if (myposy >= 11) {
                        mvwprintw(stdscr, 19, 0, "Out of bounds \n");
                        myposy = myposy - 3;
                    }
                    moveCursor(myposy, myposx);
                    break;
                }
                case KEY_LEFT:
                {
                    myposx = myposx - 6;

                    if (myposx <= 1) {
                        mvwprintw(stdscr, 19, 0, "Out of bounds \n");
                        myposx = myposx + 6;
                    }
                    moveCursor(myposy, myposx);
                    break;
                }
                case KEY_RIGHT:
                {
                    myposx = myposx + 6;

                    if (myposx >= 20) {
                        mvwprintw(stdscr, 19, 0, "Out of bounds \n");
                        myposx = myposx - 6;
                    }
                    moveCursor(myposy, myposx);
                    break;
                }
                case (32):
                {
                    player++;
                    moveCursor(myposy, myposx);
                    changeBoard(board, py, px,pp);
                    break;
                }
                default:
                {
                    break;
                }
            }
            /*See if anyone won*/
            checkWinner(boardData, winn);
            if (*winn == 1) {
                break;
            }
            /*Even or odd player */
            player = player % 2;
            mvwprintw(stdscr, 20, 0, "Player: %d", player+1);
        }
        /*Draw modified away */
        drawPieces(boardData);
        mvwprintw(stdscr, 16, 0, "Do you want to play again?");
        mvwprintw(stdscr, 17, 0, "Y for yes N for no \n");
        inputChar = getch();
        /*Determine if the user wants to play again*/
        if (inputChar == 'Y' || inputChar == 'y') {
            for (a = 0; a < 9; a++) {
                boardData[a] = '#';
                player = 0;
            }
            /*Reset the game pieces for new game*/
            moveCursor(myposy, myposx);
            clear();
            drawBoard();
            drawPieces(boardData);
            moveCursor(myposy, myposx);
            for (a = 0; a < 9; a++) {
                boardData[a] = ' ';
                player = 0;
            }
        } else if (inputChar == 'N' || inputChar == 'n') {
            mvwprintw(stdscr, 18, 0, "Okay, thanks for playing!");
            break;
        } 
        else
        {
            mvwprintw(stdscr, 18, 0, "Not a char!");
             inputChar=' ';
        }
                          
    }
    
    mvwprintw(stdscr, 19, 0, "Press any key to quit!");
    getch();

    endwin();
    return (0);
}
