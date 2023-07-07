#include "Menu.hpp"

WINDOW* Menu::borderWin;
int Menu::highestGeneratedNumber = 0;


Menu::Menu(){

    initalizeMenuBorderWindow();
    
    
}


void Menu::initalizeMenuBorderWindow(){
    int xMax = getmaxx(stdscr);
    borderWin = newwin(3, xMax, 0, 0);

    box(borderWin, 0, 0);
    wrefresh(borderWin);
}

WINDOW* Menu::getMenuBorderWindow(){
    return borderWin;
}


void Menu::showRecords(){
    
    int x, y;
    WINDOW* menuWin = getMenuBorderWindow();
    getDimentionsXY(menuWin, x, y);
    mvwprintw(menuWin, 1, x / 3, "longest run: %d", highestGeneratedNumber);
   wrefresh(menuWin);
}

void Menu::showOptions(){

}


void Menu::printSpeedToMenu(int speed) {

    if(speed >= 100)
        mvwprintw(Menu::borderWin, 1, 1, "%d", speed);

    else if (speed < 100 and speed > 9){

        mvwprintw(Menu::borderWin, 1, 2, "%d", speed);
        mvwprintw(Menu::borderWin, 1, 1, " ");
    }
    else {
        mvwprintw(Menu::borderWin, 1, 3, "%d", speed);
        mvwprintw(Menu::borderWin, 1, 1, "  ");
    }

    wrefresh(Menu::borderWin);
}


