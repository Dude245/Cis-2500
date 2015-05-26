#include<ncurses.h>
void initCurses();
/*Does everything really, moveMan is called in this*/
int drawRoom(int x, int y, char *roomArray, int len,int PosY,int PosX,int * wcount, int * health, int * pcount,int * tcount);
/*Moves the hero */
void moveMan(int posy,int posx);