#include "NCursesFunctions.hpp"

void printAt(WINDOW* win, const size_t x, const size_t y, const char ch[2]){
    mvwprintw(win,  y+1 , x+1 , ch);
}

int printAt(WINDOW* win, const size_t x, const size_t y, int passedNumber){
    return mvwprintw(win,  y+1 , x+1 , "%d", passedNumber);
}

void refreshWindow(WINDOW* win){
    wrefresh(win);
}
int getCharacter(WINDOW* win){
    return wgetch(win);
}
void timer(WINDOW* win, int speed){
    wtimeout(win, speed);
}

void startNCurses(){
    initscr(); 
    curs_set(0); 
    noecho();
    refresh();
    cbreak();
    
}

void getDimentionsXY(WINDOW* win, int& x, int& y){
    getmaxyx(win, y, x);
}

void endGame(){
    endwin();
}