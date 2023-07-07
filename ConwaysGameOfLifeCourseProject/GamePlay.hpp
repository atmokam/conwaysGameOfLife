#include "Grid.hpp"
#include "NCursesGameScreenBorder.hpp"
#include "NCursesFunctions.hpp"
#include "MenuList.hpp"
#include "Menu.hpp"
#include <tuple>


class GamePlay
{
    int generation;
    bool firstIteration;
    
    
    std::tuple<int, int, WINDOW*, MenuState> initialSetupOfGameScreen();
    
    MenuState chooseGamePlayMode();
    int chooseGamePlayMode(int speed);
    

    int speedAndControl(int speed, WINDOW* gameWin, int& speedForDisplay); 
    void startGame(const vectorSize& vectorSizeX, const vectorSize& vectorSizeY, WINDOW* NCGamePlayWindow); 
    
    void gameRunner(WINDOW* win, int speed, Grid& gameGrid);
    void increaseGenerationAndPrintToMenu(WINDOW * menuWin);
    
public:
    GamePlay();

};