/*************************roguefun.c****************************
Student Name: Nathan Reymer                  Student Number:  0797359
Date: Jan 27/13                         Course Name: CIS*2500
I have exclusive control over this submission via monsterY password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the UniversitreasureY policy on academic integritreasureY;
     2) I have completed the Computing with IntegritreasureY Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with IntegritreasureY Self Test.
I assert that this work is monsterY own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
 ****************************************************************************/
#include "rogue.h"
#include <time.h>
#include <ctype.h>
#include<stdlib.h>

void initCurses() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
}

int drawRoom(int x, int y, char *roomArray, int len, int posY, int posX, int * wcount, int * health, int * pcount, int * tcount) {
    clear();
    srand(time(NULL));
    move(0, 0);
    printw("Number of weapons: %d Health: %d Potions: %d Treasure: %d Weapons %d", *wcount, *health, *pcount, *tcount,*wcount);
    /*Define all variables*/
    int wallnum;
    int hdef = 0, randomTreasure = 0, randomPotion = 0;
    int treasureX[20], treasureY[20], monsterX[20], monsterY[20], potionX[20], potionY[20], weaponX[20], weaponY[20];
    int addNum;
    int apdnum;
    int move = 0, l = 0;
    int dot;
    int countW = 0, countT = 0, countP = 0, countM = 0;
    /*Draw the outlines of the board*/
  
 
    move(3, 2);
    vline('|', y-2);
    move(3, x+1 );
    vline('|', y-2);
    
    move(y+1 , 2);
    hline('-', x);
      move(2, 2);
    hline('-', x);
 
    /*Draw the floor*/
    for (dot = 3; dot < (y+1); dot++) {
        move(dot, 3);
        hline('.', x - 2);
    }
    /*Go through each character of the room line and check if 'this'*/
    for (l = 0; l < len + 1; l++) {
        if (roomArray[l] != 'd') {
            if (roomArray[l] == 't') {
                /*My way to get around xx dimensions when reading 1 character*/
                if (roomArray[l + 3] == ',') {
                    addNum = (roomArray[l + 1]);
                    addNum = addNum - 48;
                    addNum = addNum * 10;
                    apdnum = roomArray[l + 2];
                    apdnum = apdnum - 48;
                    addNum = addNum + apdnum;
                    treasureX[countT] = addNum;
                    addNum = (roomArray[l + 4]);
                    addNum = addNum - 48;
                    addNum = addNum * 10;
                    apdnum = roomArray[l + 5];
                    apdnum = apdnum - 48;
                    addNum = addNum + apdnum;
                    treasureY[countT] = addNum+2;
                } else {

                    treasureX[countT] = roomArray[l + 1];
                    treasureX[countT] = treasureX[countT] - 46;
                    treasureY[countT] = roomArray[l + 3];
                    treasureY[countT] = treasureY[countT] - 46;
                }
                /*If hero moves to piece, remove piece, add letter for counter*/
                if ((posY == treasureX[countT]) && (posX == treasureY[countT])) {

                    roomArray[l + 1] = '?';
                    roomArray[l + 3] = ' ';
                    randomTreasure = (rand() % 20) + 1;
                    *tcount = *tcount + randomTreasure;
                    move(1, 0);
                    printw("You picked up %d treasure!", randomTreasure);
                }
                /*Draw whatever pieces are left*/
                mvwprintw(stdscr, treasureX[countT], treasureY[countT], "*");
                countT++;

            }
            if (roomArray[l] == 'm') {
                if (roomArray[l + 3] == ',') {
                    addNum = (roomArray[l + 1]);
                    addNum = addNum - 48;
                    addNum = addNum * 10;
                    apdnum = roomArray[l + 2];
                    apdnum = apdnum - 48;
                    addNum = addNum + apdnum;
                    monsterX[countM] = addNum;
                    addNum = (roomArray[l + 4]);
                    addNum = addNum - 48;
                    addNum = addNum * 10;
                    apdnum = roomArray[l + 5];
                    apdnum = apdnum - 48;
                    addNum = addNum + apdnum;
                    monsterY[countM] = addNum;
                } else {
                    monsterX[countM] = roomArray[l + 1];
                    monsterX[countM] = monsterX[countM] - 46;
                    monsterY[countM] = roomArray[l + 3];
                    monsterY[countM] = monsterY[countM] - 46;

                }
                if ((posY == monsterX[countM]) && (posX == monsterY[countM])) {
                    /*Seed random number for damage */
                    hdef = (rand() % 30) + 1;
                    if (hdef % 2 == 1) {
                        move(1, 0);
                        printw("You hit the monster and lost %d health!", hdef);
                        *health = *health - hdef;
                    }
                    else if (hdef % 2 == 0) {
                        roomArray[l + 1] = '?';
                        roomArray[l + 3] = ' ';
                        move(1, 0);
                        printw("You killed the monster!");
                    }

                }
                mvwprintw(stdscr, monsterX[countM], monsterY[countM], "m");
                countM++;
            }
            if (roomArray[l] == 'p') {
                if (roomArray[l + 3] == ',') {
                    addNum = (roomArray[l + 1]);
                    addNum = addNum - 48;
                    addNum = addNum * 10;
                    apdnum = roomArray[l + 2];
                    apdnum = apdnum - 48;
                    addNum = addNum + apdnum;
                    potionX[countP] = addNum;
                    addNum = (roomArray[l + 4]);
                    addNum = addNum - 48;
                    addNum = addNum * 10;
                    apdnum = roomArray[l + 5];
                    apdnum = apdnum - 48;
                    addNum = addNum + apdnum;
                    potionY[countP] = addNum;
                } else {

                    potionX[countP] = roomArray[l + 1];
                    potionX[countP] = potionX[countP] - 46;
                    potionY[countP] = roomArray[l + 3];
                    potionY[countP] = potionY[countP] - 46;
                }
                if ((posY == potionX[countP]) && (posX == potionY[countP])) {
                    randomPotion = (rand() % 10) + 1;
                    roomArray[l + 1] = '?';
                    roomArray[l + 3] = ' ';

                    *pcount = *pcount + randomPotion;
                    move(1, 0);
                    printw("You picked up %d potion!", randomPotion);

                }
                mvwprintw(stdscr, potionX[countP], potionY[countP], "!");
                countP++;


            }
            if (roomArray[l] == 'w' && roomArray[l - 1] != 'd') {
                if (roomArray[l + 3] == ',') {
                    addNum = (roomArray[l + 1]);
                    addNum = addNum - 48;
                    addNum = addNum * 10;
                    apdnum = roomArray[l + 2];
                    apdnum = apdnum - 48;
                    addNum = addNum + apdnum;
                    weaponX[countW] = addNum;
                    addNum = (roomArray[l + 4]);
                    addNum = addNum - 48;
                    addNum = addNum * 10;
                    apdnum = roomArray[l + 5];
                    apdnum = apdnum - 48;
                    addNum = addNum + apdnum;
                    weaponY[countW] = addNum;
                } else {
                    weaponX[countW] = roomArray[l + 1];
                    weaponX[countW] = weaponX[countW] - 46;
                    weaponY[countW] = roomArray[l + 3];
                    weaponY[countW] = weaponY[countW] - 46;
                }

                if ((posY == weaponX[countW]) && (posX == weaponY[countW])) {

                    roomArray[l + 1] = '?';
                    roomArray[l + 3] = ' ';
                    *wcount = *wcount + 1;
                    move(1, 0);
                    printw("You picked up a weapon! ");
                }
                mvwprintw(stdscr, weaponX[countW], weaponY[countW], ")");
                countW++;
            }
            /*Code for doors, same as monsters, scan entire room line*/
        } else if (roomArray[l] == 'd' && (roomArray[l + 1] == 'n' || roomArray[l + 1] == 's' || roomArray[l + 1] == 'e' || roomArray[l + 1] == 'w')) {

            if (roomArray[l + 1] == 'e') {
                if (roomArray[l + 3] == ',') {
                    addNum = (roomArray[l + 1]);
                    addNum = addNum - 48;
                    addNum = addNum * 10;
                    apdnum = roomArray[l + 2];
                    apdnum = apdnum - 48;
                    addNum = addNum + apdnum;
                    wallnum = addNum;
                } else {
                    wallnum = roomArray[l + 2];
                    wallnum = wallnum - 46;
                    mvwprintw(stdscr, wallnum, x+1 , "+");
                }
                /*Another way to advance to another room*/
                if (posY == wallnum && posX == x ) {
                    move = 1;
                }
            }
        }

        if (roomArray[l + 1] == 'w') {
            if (roomArray[l + 3] == ',') {
                addNum = (roomArray[l + 1]);
                addNum = addNum - 48;
                addNum = addNum * 10;
                apdnum = roomArray[l + 2];
                apdnum = apdnum - 48;
                addNum = addNum + apdnum;
                wallnum = addNum;
            } else {
                wallnum = roomArray[l + 2];
                wallnum = wallnum - 46;
                mvwprintw(stdscr, wallnum , 2, "+");
            }
            if (posX == 3 && posY == wallnum) {
                move = 1;
            }
        }

        if (roomArray[l + 1] == 's') {
            if (roomArray[l + 3] == ',') {
                addNum = (roomArray[l + 1]);
                addNum = addNum - 48;
                addNum = addNum * 10;
                apdnum = roomArray[l + 2];
                apdnum = apdnum - 48;
                addNum = addNum + apdnum;
                wallnum = addNum;
            } else {
                wallnum = roomArray[l + 2];
                wallnum = wallnum - 48;
            }
            mvwprintw(stdscr, y+1 , wallnum+2, "+");
            if (posX == wallnum+2 && posY == y) {
                move = 1;
            }
        }

        if (roomArray[l + 1] == 'n') {
            if (roomArray[l + 3] == ',') {
                addNum = (roomArray[l + 1]);
                addNum = addNum - 48;
                addNum = addNum * 10;
                apdnum = roomArray[l + 2];
                apdnum = apdnum - 48;
                addNum = addNum + apdnum;
                wallnum = addNum;
            } else {
                wallnum = roomArray[l + 2];
                wallnum = wallnum - 48;
            }
            mvwprintw(stdscr, 2, wallnum + 2, "+");
            if (posY == 3 && posX == wallnum + 2) {
                move = 1;
            }
        }
    }
    /*Finally move character after everything is drawn*/
    moveMan(posY, posX);
    /*See if the player wants to move*/
    return move;
}

void moveMan(int posy, int posx) {
    /*Draw the @ symbol where the cursor is*/
    mvwprintw(stdscr, posy, posx, "@");
    move(posy, posx);
    refresh();
}
