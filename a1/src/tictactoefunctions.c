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

void initCurses() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

}

void drawBoard() {
    move(5, 6);
    hline('_', 15);
    move(8, 6);
    hline('_', 15);


    move(4, 16);
    vline('|', 7);
    move(4, 10);
    vline('|', 7);

    move(0, 0);
    refresh();
}

void moveCursor(int posy, int posx) {
    mvwprintw(stdscr, posy, posx, "[]");
    refresh();
}

void drawPieces(char * board) {
    mvwprintw(stdscr, 4, 7, "%c", *board);
    board++;
    mvwprintw(stdscr, 4, 13, "%c", *board);
    board++;
    mvwprintw(stdscr, 4, 19, "%c", *board);
    board++;
    mvwprintw(stdscr, 7, 7, "%c", *board);
    board++;
    mvwprintw(stdscr, 7, 13, "%c", *board);
    board++;
    mvwprintw(stdscr, 7, 19, "%c", *board);
    board++;
    mvwprintw(stdscr, 10, 7, "%c", *board);
    board++;
    mvwprintw(stdscr, 10, 13, "%c", *board);
    board++;
    mvwprintw(stdscr, 10, 19, "%c", *board);
}

void changeBoard(char * board, int *x, int * y, int *p) {
    if (*x == 4 && *y == 7) {
        if ((*board == 'X') || (*board == 'O')) {
            mvwprintw(stdscr, 21, 0, "Already taken");
            *p = *p - 1;
        } else if (*p == 1) {
            *board = 'X';
        } else if (*p == 2) {
            *board = 'O';
        } else {
            *board = *board;
        }
    }

    if (*x == 4 && *y == 13) {
        board = board + 1;
        if ((*board == 'X') || (*board == 'O')) {
            mvwprintw(stdscr, 21, 0, "Already taken");
            *p = *p - 1;
        } else if (*p == 1) {
            *board = 'X';
        } else if (*p == 2) {
            *board = 'O';
        } else {
            *board = *board;
        }
    }
    if (*x == 4 && *y == 19) {
        board = board + 2;
        if ((*board == 'X') || (*board == 'O')) {
            mvwprintw(stdscr, 21, 0, "Already taken");
            *p = *p - 1;
        } else if (*p == 1) {
            *board = 'X';
        } else if (*p == 2) {
            *board = 'O';
        } else {
            *board = *board;
        }
    }
    if (*x == 7 && *y == 7) {
        board = board + 3;
        if ((*board == 'X') || (*board == 'O')) {
            mvwprintw(stdscr, 21, 0, "Already taken");
            *p = *p - 1;
        } else if (*p == 1) {
            *board = 'X';
        } else if (*p == 2) {
            *board = 'O';
        } else {
            *board = *board;
        }
    }
    if (*x == 7 && *y == 13) {
        board = board + 4;
        if ((*board == 'X') || (*board == 'O')) {
            mvwprintw(stdscr, 21, 0, "Already taken");
            *p = *p - 1;
        } else if (*p == 1) {
            *board = 'X';
        } else if (*p == 2) {
            *board = 'O';
        } else {
            *board = *board;
        }
    }
    if (*x == 7 && *y == 19) {
        board = board + 5;
        if ((*board == 'X') || (*board == 'O')) {
            mvwprintw(stdscr, 21, 0, "Already taken");
            *p = *p - 1;
        } else if (*p == 1) {
            *board = 'X';
        } else if (*p == 2) {
            *board = 'O';
        } else {
            *board = *board;
        }
    }
    if (*x == 10 && *y == 7) {
        board = board + 6;
        if ((*board == 'X') || (*board == 'O')) {
            mvwprintw(stdscr, 21, 0, "Already taken");
            *p = *p - 1;
        } else if (*p == 1) {
            *board = 'X';
        } else if (*p == 2) {
            *board = 'O';
        } else {
            *board = *board;
        }
    }
    if (*x == 10 && *y == 13) {
        board = board + 7;
        if ((*board == 'X') || (*board == 'O')) {
            mvwprintw(stdscr, 21, 0, "Already taken");
            *p = *p - 1;
        }
        if (*p == 1) {
            *board = 'X';
        }
        if (*p == 2) {
            *board = 'O';
        } else {
            *board = *board;
        }
    }
    if (*x == 10 && *y == 19) {
        board = board + 8;
        if ((*board == 'X') || (*board == 'O')) {
            mvwprintw(stdscr, 21, 0, "Already taken");
            *p = *p - 1;
        } else if (*p == 1) {
            *board = 'X';
        } else if (*p == 2) {
            *board = 'O';
        } else {
            *board = *board;
        }
    }
}

int checkWinner(char* board, int * winn) {
    if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X') {
        mvwprintw(stdscr, 15, 0, "X Wins");
        *winn = 1;
    }
    if (board[3] == 'X' && board[4] == 'X' && board[5] == 'X') {
        mvwprintw(stdscr, 15, 0, "X Wins");
        *winn = 1;
    }
    if (board[6] == 'X' && board[7] == 'X' && board[8] == 'X') {
        mvwprintw(stdscr, 15, 0, "X Wins");
        *winn = 1;
    }
    if (board[0] == 'O' && board[1] == 'O' && board[2] == 'O') {
        mvwprintw(stdscr, 15, 0, "O Wins");
        *winn = 1;
    }
    if (board[3] == 'O' && board[4] == 'O' && board[5] == 'O') {
        mvwprintw(stdscr, 15, 0, "O Wins");
        *winn = 1;
    }
    if (board[6] == 'O' && board[7] == 'O' && board[8] == 'O') {
        mvwprintw(stdscr, 15, 0, "O Wins");
        *winn = 1;
    }
    if (board[0] == 'X' && board[4] == 'X' && board[8] == 'X') {
        mvwprintw(stdscr, 15, 0, "X Wins");
        *winn = 1;
    }
    if (board[2] == 'X' && board[4] == 'X' && board[6] == 'X') {
        mvwprintw(stdscr, 15, 0, "X Wins");
        *winn = 1;
    }
    if (board[0] == 'O' && board[4] == 'O' && board[8] == 'O') {
        mvwprintw(stdscr, 15, 0, "O Wins");
        *winn = 1;
    }
    if (board[2] == 'O' && board[4] == 'O' && board[6] == 'O') {
        mvwprintw(stdscr, 15, 0, "O Wins");
        *winn = 1;
    }
    if (board[0] == 'O' && board[3] == 'O' && board[6] == 'O') {
        mvwprintw(stdscr, 15, 0, "O Wins");
        *winn = 1;
    }
    if (board[0] == 'X' && board[3] == 'X' && board[6] == 'X') {
        mvwprintw(stdscr, 15, 0, "X Wins");
        *winn = 1;
    }
    if (board[1] == 'O' && board[4] == 'O' && board[7] == 'O') {
        mvwprintw(stdscr, 15, 0, "O Wins");
        *winn = 1;
    }
    if (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') {
        mvwprintw(stdscr, 15, 0, "X Wins");
        *winn = 1;
    }
    if (board[2] == 'O' && board[5] == 'O' && board[8] == 'O') {
        mvwprintw(stdscr, 15, 0, "O Wins");
        *winn = 1;
    }
    if (board[2] == 'X' && board[5] == 'X' && board[8] == 'X') {
        mvwprintw(stdscr, 15, 0, "X Wins");
        *winn = 1;
    }
    if (board[0] == 'X' && board[2] == 'X' && board[4] == 'X' && board[6] == 'X' && board[8] == 'X') {
        mvwprintw(stdscr, 15, 0, "X Wins");
        *winn = 1;
    }
    int i;
    i = 0;
    int cats = 1;
    while (i < 10) {
        if (board[i] == ' ') {
            cats++;
        }
        i++;
    }
    if (cats == 1 && *winn == 1) {
        mvwprintw(stdscr, 15, 0, "X wins");
        *winn = 1;
    } else if (cats == 1) {
        mvwprintw(stdscr, 15, 0, "Cats Game");
        *winn = 1;
    }
    return (*winn);
}
