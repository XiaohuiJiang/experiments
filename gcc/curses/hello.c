/*-----------------------------------------------------------------
A very simple example of curses programming
coder: jellen
date: 3-26-2004
----------------------------------------------------------------*/
#include <curses.h>
int main()
{
initscr();
box(stdscr, ACS_VLINE, ACS_HLINE); /*draw a box*/
move(LINES/2, COLS/2); /*move the cursor to the center*/
waddstr(stdscr, "Hello, world!");
refresh();
getch();
endwin();
return 0;
}

// gcc -o hello hello.c -lcurses