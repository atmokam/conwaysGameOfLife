
#include "Grid.hpp"

#include "NCursesFunctions.hpp"




Grid::Grid(const vectorSize rowsOfVector, const vectorSize colsOfVector) : boundX(rowsOfVector), boundY(colsOfVector) {

        std::vector<std::vector<vectorSize>> display(rowsOfVector, std::vector<vectorSize>(colsOfVector, 0));
        
        displayGrid = display;

        initializeDisplayGridVector();

   
}

void Grid::initializeDisplayGridVector() {
    
        populateWithRandom();
}



int Grid::isCenterCellAlive(const vectorSize CellX, const vectorSize CellY, std::vector<std::vector<vectorSize>>& display) {
    int aliveCount = 0;


    //corners

    if ((CellY == 0) && (CellX == boundX - 1)) { //lower left

        if (displayGrid[CellX - 1][CellY + 1] == 1) ++aliveCount;
        if (displayGrid[CellX][CellY + 1] == 1) ++aliveCount;
        if (displayGrid[CellX - 1][CellY] == 1) ++aliveCount;

    }

    else if ((CellX == 0) && (CellY == boundY - 1)) { //upper right

        if (displayGrid[CellX + 1][CellY] == 1) ++aliveCount;
        if (displayGrid[CellX + 1][CellY - 1] == 1) ++aliveCount;
        if (displayGrid[CellX][CellY - 1] == 1) ++aliveCount;

    }

    else if ((CellY == 0) && (CellX == 0)) { //upper left

        if (displayGrid[CellX][CellY + 1] == 1) ++aliveCount;
        if (displayGrid[CellX + 1][CellY + 1] == 1) ++aliveCount;
        if (displayGrid[CellX + 1][CellY] == 1) ++aliveCount;
    }

    else if ((CellY == boundY - 1) && (CellX == boundX - 1)) {  //lower right

        if (displayGrid[CellX][CellY - 1] == 1) ++aliveCount;
        if (displayGrid[CellX - 1][CellY] == 1) ++aliveCount;
        if (displayGrid[CellX - 1][CellY - 1] == 1) ++aliveCount;
    }

    else if (CellY == 0) {  //middle part : left

        if (displayGrid[CellX + 1][CellY] == 1) ++aliveCount;
        if (displayGrid[CellX - 1][CellY] == 1) ++aliveCount;
        if (displayGrid[CellX + 1][CellY + 1] == 1) ++aliveCount;
        if (displayGrid[CellX][CellY + 1] == 1) ++aliveCount;
        if (displayGrid[CellX - 1][CellY + 1] == 1) ++aliveCount;
    }

    else if (CellY == boundY - 1) {//middle part : right

        if (displayGrid[CellX + 1][CellY] == 1) ++aliveCount;
        if (displayGrid[CellX - 1][CellY] == 1) ++aliveCount;
        if (displayGrid[CellX + 1][CellY - 1] == 1) ++aliveCount;
        if (displayGrid[CellX][CellY - 1] == 1) ++aliveCount;
        if (displayGrid[CellX - 1][CellY - 1] == 1) ++aliveCount;
    }

    else if (CellX == 0) { //middle part :  up

        if (displayGrid[CellX + 1][CellY - 1] == 1) ++aliveCount;
        if (displayGrid[CellX + 1][CellY] == 1) ++aliveCount;
        if (displayGrid[CellX + 1][CellY + 1] == 1) ++aliveCount;
        if (displayGrid[CellX][CellY - 1] == 1) ++aliveCount;
        if (displayGrid[CellX][CellY + 1] == 1) ++aliveCount;
    }

    else if (CellX == boundX - 1) { //middle part : down

        if (displayGrid[CellX - 1][CellY - 1] == 1) ++aliveCount;
        if (displayGrid[CellX - 1][CellY] == 1) ++aliveCount;
        if (displayGrid[CellX - 1][CellY + 1] == 1) ++aliveCount;
        if (displayGrid[CellX][CellY - 1] == 1) ++aliveCount;
        if (displayGrid[CellX][CellY + 1] == 1) ++aliveCount;
    }

    else {                          //the rest of the cells
        if (displayGrid[CellX + 1][CellY - 1] == 1) ++aliveCount;
        if (displayGrid[CellX + 1][CellY] == 1) ++aliveCount;
        if (displayGrid[CellX + 1][CellY + 1] == 1) ++aliveCount;
        if (displayGrid[CellX][CellY - 1] == 1) ++aliveCount;
        if (displayGrid[CellX][CellY + 1] == 1) ++aliveCount;
        if (displayGrid[CellX - 1][CellY - 1] == 1) ++aliveCount;
        if (displayGrid[CellX - 1][CellY + 1] == 1) ++aliveCount;
        if (displayGrid[CellX - 1][CellY] == 1) ++aliveCount;

    }


    

    if (displayGrid[CellX][CellY] == 1 && aliveCount == 2) return 1; //survival

    else if (aliveCount < 2 || aliveCount > 3) return 0;             //death

    else if (aliveCount == 3) return 1;                              //birth

    return 0;
}





void Grid::getNextStateVectorAndOutputTo(WINDOW* win) {


    std::vector<std::vector<vectorSize>> tempGrid(boundX, std::vector<vectorSize>(boundY, 0));

    for (vectorSize i = 0; i < displayGrid.size(); ++i) 
        for (vectorSize j = 0; j < displayGrid[i].size(); ++j) {
            tempGrid[i].at(j) = isCenterCellAlive(i, j, displayGrid);
            printState(win, i, j, tempGrid[i][j]);
        }
    
    displayGrid = tempGrid;
    refreshWindow(win);

}



void Grid::populateWithRandom(){

    srand(time(NULL));

    for(auto& vect : displayGrid)
        for(auto& num : vect)
            num = rand() % 2;
        

}



void Grid::printState(WINDOW* win, const vectorSize x, const vectorSize y, const int cell){      
        start_color(); 
        init_pair(1,COLOR_CYAN, COLOR_BLACK);
        wattron(win, COLOR_PAIR(1));

        if(cell == 1)
            printAt(win, x, y, "|");
        else
            printAt(win, x, y, " ");


}
