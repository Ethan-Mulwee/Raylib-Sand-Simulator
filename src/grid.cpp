#include "grid.hpp"
#include "raylib.h"
#include "stdio.h"
#include "string"

void Grid::Step() {
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            cells[row][column]->update(this, row, column);
        }
    }
}

void Grid::Draw(){
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            if (!cells[row][column]->empty) DrawRectangle(column*cellSize, row*cellSize, cellSize, cellSize,cells[row][column]->color);
        }
    }
}

void Grid::Set(int row, int column, std::shared_ptr<Cell> celltype) {
    //if within bounds
    if (row < rows && row > -1 && column < columns && column > -1) {
        cells[row][column] = celltype;
    }
}


void Grid::Sand::update(Grid* grid, int row, int column)
{
    (*grid).cells[row+1][column]->color = RED;
}
