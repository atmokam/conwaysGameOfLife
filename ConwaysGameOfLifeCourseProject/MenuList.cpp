#include "MenuList.hpp"
#include "NCursesFunctions.hpp"



void MenuList::initializeGameMode(){

    drawMenuDropDown();

    selectedMenuItem = chooseStateOfMenu();


}




MenuList::MenuList(int x) : positionX(x){


    menuListWin = newwin(1, 7*sizeOfList, 1, positionX - 7*sizeOfList - 2);
    keypad(menuListWin, true);

    initializeGameMode();

} 

MenuState MenuList::chooseStateOfMenu(){

    

    int charGotten;  int index = 0;
    while(charGotten = wgetch(menuListWin)) {
        switch (charGotten)
        {
        case KEY_RIGHT:
            dehighLightSelected(index, menuListWin, sizeOfList);
            selectNext(index, menuListWin, sizeOfList);
            highLightSelected(index, menuListWin, sizeOfList);
            break;

        case KEY_LEFT:
            dehighLightSelected(index, menuListWin, sizeOfList);
            selectPrevious(index, menuListWin, sizeOfList);
            highLightSelected(index, menuListWin, sizeOfList);
            break;
        
        case '\n':
            
            return (MenuState)index;
        default:
            break;
        }
    }
    return (MenuState)0;

}



void MenuList::selectNext(int& index, WINDOW* win, int size){
    index++;
    if(index >= size)
        index = 0;
}

void MenuList::selectPrevious(int& index, WINDOW* win, int size){
    index--;
    if(index < 0)
        index = size-1;
}


void MenuList::dehighLightSelected(int index, WINDOW* win, int size){ 
   
    mvwchgat(win, 0, index + index *7, 7, A_NORMAL, 0, NULL);
}


void MenuList::highLightSelected(int index, WINDOW* win, int size){ 
   
    mvwchgat(win, 0,  index + index*7, 7, A_STANDOUT, 0, NULL);
}

void MenuList::drawMenuDropDown(){

    for(int i = 0; i < sizeof(menuStateList)/sizeof(menuStateList[0]); ++i){
        mvwprintw(menuListWin, 0, i + i*7, menuStateList[i].c_str());
    }
    highLightSelected(0, menuListWin, sizeOfList);
    wrefresh(menuListWin);

}



void MenuList::removeMenuDropDown(){
    werase(menuListWin);
    keypad(menuListWin, false);

}
