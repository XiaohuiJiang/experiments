/*--------------------------------------------------------------
A simple curses color demo program
Coder: jellen
Date: 3-26-2004
-------------------------------------------------------------*/
#include <curses.h>
int main()
{
initscr(); /*初始化屏幕*/
if(start_color() == OK) /*开启颜色*/
{
init_pair(1, COLOR_RED, COLOR_GREEN); /*建立一个颜色对*/
attron(COLOR_PAIR(1)); /*开启字符输出颜色*/
move(LINES/2, COLS/2);
waddstr(stdscr, "Yet another Hello, world!");
attroff(COLOR_PAIR(1)); /*关闭颜色显示*/
refresh();
getch();
}
else
{
waddstr(stdscr, "Can not init color");
refresh();
getch();
}
endwin(); /*关闭curses状态*/
return 0;
}

// gcc -o color color.c -lcurses

//http://www.ibm.com/developerworks/cn/aix/library/au-shellcurses/index.html
