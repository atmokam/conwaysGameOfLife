#include "GamePlay.hpp"



GamePlay::GamePlay(){

    startNCurses();

    firstIteration = true;

    chooseGamePlayMode();
    
}



std::tuple<int, int, WINDOW*, MenuState> GamePlay::initialSetupOfGameScreen(){
   
    

    NCursesGameScreenBorder gameBorder;
    Menu menuObject;
    
    
    int returnedX, returnedY;
    getDimentionsXY(gameBorder.borderWin, returnedX, returnedY);

    
    MenuList list(returnedX);
    MenuState state = list.selectedMenuItem;

    
    keypad(gameBorder.borderWin, true);

    return {returnedX - 2, returnedY - 2, gameBorder.borderWin, state};
   
    

}


MenuState GamePlay::chooseGamePlayMode(){

    auto [resolutionX, resolutionY, NCGamePlayWindow, menuState] = initialSetupOfGameScreen();

    if(menuState == MenuState::Exit && !(firstIteration)){
        return MenuState::Exit;
    } 
    else if(menuState == MenuState::Exit){
        endGame();
        return MenuState::Exit;

    }


    if(menuState == MenuState::Options && !(firstIteration)){
        //toggleOption();???
        return MenuState::Options;
    }
    else if(menuState == MenuState::Options){
        chooseGamePlayMode();
        return MenuState::Options;

    }
    

    if(menuState == MenuState::Records && !(firstIteration)){
        Menu::showRecords();
        return MenuState::Records;
    }
    else if(menuState == MenuState::Records){
        chooseGamePlayMode();
        return MenuState::Records;
    }


    if(menuState == MenuState::Play)
        firstIteration = false;
    

    if(generation > Menu::highestGeneratedNumber)
        Menu::highestGeneratedNumber = generation;
    

    
    startGame(resolutionX, resolutionY, NCGamePlayWindow);
}






void GamePlay::startGame(const vectorSize& vectorSizeX, const vectorSize& vectorSizeY, WINDOW* NCGamePlayWindow) {

    
    Grid gameScreenGrid(vectorSizeX, vectorSizeY);
    gameRunner(NCGamePlayWindow, 300, gameScreenGrid);
}






int GamePlay::speedAndControl(int speed, WINDOW* gameWin, int& speedForDisplay)
{
    
    int input = getCharacter(gameWin);
    int optionChosen;

    while ( input != ERR )
    {
        
        switch(input) {
            
            case KEY_LEFT:
            if(speed <= 590){
                speed += 10;
                speedForDisplay -= 10; 
                Menu::printSpeedToMenu(speedForDisplay / 10);
            } 
            break;

            case KEY_RIGHT:
            if(speed >= 20){
                speed -= 10;
                speedForDisplay += 10;
                Menu::printSpeedToMenu(speedForDisplay / 10);
            } 
            break;

            case 'm':
                optionChosen = chooseGamePlayMode(speed);
                speed = optionChosen;
                break;

            default:
                break;
        }
        input = getCharacter(gameWin);
        
    }

    return speed;
}




int GamePlay::chooseGamePlayMode(int preservedSpeed){

    MenuState optionChosen = chooseGamePlayMode();

        if(optionChosen == MenuState::Exit)

            return -1;

        else if(optionChosen == MenuState::Options || optionChosen == MenuState::Records)
            
            return preservedSpeed;
        
        

}






void GamePlay::gameRunner(WINDOW* win, int speed, Grid& gameGrid){

    generation = 0;

    WINDOW* menuWin = Menu::getMenuBorderWindow(); //static member getter
    int speedForDisplay = speed;
    
    do{
        timer(win, speed);
        speed = speedAndControl(speed, win, speedForDisplay);
       
        if(speed == -1 || speed == 0) 
            break;

        gameGrid.getNextStateVectorAndOutputTo(win);
        increaseGenerationAndPrintToMenu(menuWin);

        
    } while(true);
    endGame();
}




void GamePlay::increaseGenerationAndPrintToMenu(WINDOW* menuWin){

    generation++;
    
    mvwprintw(menuWin, 1, 10, "%d", generation); //can't change

    refreshWindow(menuWin);
}

