#include "ncurses.h"
void initCurses();
/* You will want a function to draw the board and likely a separate one to draw the pieces */
void drawBoard();
/*Changes the array based on player and position*/
void changeBoard(char * board, int *x, int * y, int *p);
/* moves the cusros, refreash the screen */
void moveCursor(int posy, int posx);
/*Draw the array on the board in my positons */
void drawPieces(char * board);
/*Check if anyone won the game*/
int checkWinner(char* board, int* win);