#ifndef MENUDROPDOWN
#define MENUDROPDOWN

#include<ncurses.h>
#include "Menu.hpp"
#include <string>


class MenuList{

    int positionX;
    int sizeOfList = sizeof(menuStateList)/sizeof(menuStateList[0]);


    void removeMenuDropDown();

    void dehighLightSelected(int index, WINDOW* win,  int size);
    void highLightSelected(int index, WINDOW* win, int size);
    void selectNext(int& index, WINDOW* win, int size);
    void selectPrevious(int& index, WINDOW* win, int size);
    void drawMenuDropDown();
    
public:


    WINDOW* menuListWin;
    MenuState selectedMenuItem;
    
    MenuList(int x); 
    
    
    const std::string menuStateList[4] = {"Play", "Options", "Records", "Quit"};    //make separate menu drop down list with destructor
    
    

    void initializeGameMode();
         
    MenuState chooseStateOfMenu();


};
















#endif