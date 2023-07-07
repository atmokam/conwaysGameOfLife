#ifndef GRID
#define GRID

#include<array>
#include<iostream>
#include<vector>
#include <ncurses.h>

#include <time.h>
// Any live cell with fewer than two live neighbours dies, as if by underpopulation.
// Any live cell with more than three live neighbours dies, as if by overpopulation.

// Any live cell with two or three live neighbours lives on to the next generation.
// Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

using vectorSize = std::size_t;

class Grid
{
public:
    
    Grid(const vectorSize rowsOfVector, const vectorSize colsOfVector);


    void printState(WINDOW* win, const vectorSize x, const vectorSize y, const int cell);
    void getNextStateVectorAndOutputTo(WINDOW* win);


private:
    void initializeDisplayGridVector();
    int isCenterCellAlive(const vectorSize CellX, const vectorSize CellY, std::vector<std::vector<vectorSize>>& display);
    void populateWithRandom();
	std::vector<std::vector<vectorSize>> displayGrid ; 

    vectorSize boundX, boundY;


};
#endif