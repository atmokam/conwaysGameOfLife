#include "NCursesGameScreenBorder.hpp"


NCursesGameScreenBorder::NCursesGameScreenBorder() {
        int xMax, yMax;

        getmaxyx(stdscr, yMax, xMax);
        
        borderWin = newwin(yMax - 2, xMax, 2, 0);
        
        box(borderWin, 0, 0);
        wrefresh(borderWin);
       
}

