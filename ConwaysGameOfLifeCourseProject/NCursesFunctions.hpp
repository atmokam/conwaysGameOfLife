#ifndef NCURSES_FUNCTIONS
#define NCURSES_FUNCTIONS
#include <ncurses.h>

void printAt(WINDOW* win, const size_t x, const size_t y, const char ch[2]);
int printAt(WINDOW* win, const size_t x, const size_t y, int passedNumber);
void refreshWindow(WINDOW* win);
int getCharacter(WINDOW* win);
void timer(WINDOW* win, int speed);

void startNCurses();
void getDimentionsXY(WINDOW* win, int& x, int& y);

void endGame(); 



#endif



