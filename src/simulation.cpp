#include "simulation.hpp"
#include "raylib.h"
#include "stdio.h"
#include "string"


void Step() {
    for (int row = rows-1; row >= 0; row--) {
        for (int column = 0; column < columns; column++) {
            cells[row][column]->update(row, column);
        }
    }
}

void Draw(){
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            if (!cells[row][column]->empty) DrawRectangle(column*cellSize, row*cellSize, cellSize, cellSize,cells[row][column]->color);
        }
    }
}

void Set(int row, int column, std::shared_ptr<Cell> celltype) {
    //if within bounds
    if (row < rows && row > -1 && column < columns && column > -1) {
        cells[row][column] = celltype;
    }
}


void Sand::update(int row, int column)
{
    if (row+1 == rows-1) return;
    if (cells[row+1][column]->empty) {
        Set(row+1, column, std::make_shared<Sand>(WHITE));
    }
}
