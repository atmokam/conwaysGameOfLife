#ifndef MENU
#define MENU
#include "NCursesFunctions.hpp"

enum class MenuState : int{
    Play = 0,
    Options = 1,
    Records = 2,
    Exit = 3
};

class Menu{

    static WINDOW* borderWin; //menu border window

public:
    static int highestGeneratedNumber;
    

    Menu();
    void initalizeMenuBorderWindow(); 
    
    MenuState initializeGameMode();
    


    static void showRecords();
    static void showOptions();
    static WINDOW* getMenuBorderWindow();
    static void printSpeedToMenu(int speed);
    

};





#endif