#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

int main() {



 refresh();
  getch();
  endwin();
  return(0);
}
/*printw("Hello World");*/
 /*for (i=1; i<10; i++){
   move(i, i*5);
   printw("Hello World");

   }*/

/*      move(4, 15);
	printw("Hello World")*/


/*int rows;
  int cols; 
  char * mesg;
  char input[5];
  int i;
  int tall;
  int wide;
 
  initscr();
  getmaxyx(stdscr, rows, cols);
  mesg = "Enter the height ";
  mvprintw(rows-2, 0, "%s", mesg);
  getstr(input);
  tall = (int)strtol(input, NULL, 10);
  mesg = "Enter the width    ";
  mvprintw(rows-2, 0, "%s", mesg);
  getstr(input);
  wide = (int)strtol(input, NULL, 10);
  for (i=0; i<wide; i++)
    {
      mvaddch(0, i, '#');
    }
   for (i=0; i<tall; i++)
   {
     mvaddch(i, 0, '#');
     mvaddch(i, wide, '#');
   }
   for (i=0; i<wide; i++)
    {
      mvaddch(tall, i, '#');
    }
*/
