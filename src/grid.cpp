#include "grid.hpp"
#include "raylib.h"
#include "stdio.h"
#include "string"

void Grid::Draw(){
    int SandCount = 0;
    int WaterCount = 0;
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            cells[row][column]->update();
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

void Grid::Step() {

}

// bool Grid::CheckEmpty(int row, int rowOffset, int column, int columnOffset)
// {
//     if (column+columnOffset < columns && column+columnOffset >= 0 && row + rowOffset < rows && row+rowOffset >= 0) {
//         return cells[row + rowOffset][column + columnOffset].state == EMPTY && !cells[row][column].updated && !cells[row+rowOffset][column+columnOffset].updated;
//     }
//     return false;
// }

// bool Grid::CheckCell(int row, int rowOffset, int column, int columnOffset, Grid::State stateInput)
// {
//     if (column+columnOffset < columns && column+columnOffset >= 0 && row + rowOffset < rows && row+rowOffset >= 0) {
//         return cells[row + rowOffset][column + columnOffset].state == stateInput && !cells[row][column].updated && 2 > cells[row+rowOffset][column+columnOffset].updated;
//     }
//     return false;
// }

// //Return true if in bounds and false if out of bounds
// bool Grid::MoveCell(int row, int rowOffset, int column, int columnOffset)
// {
//     if (column+columnOffset < columns && column+columnOffset >= 0 && row + rowOffset < rows && row+rowOffset >= 0) {
//         cells[row + rowOffset][column + columnOffset].color = cells[row][column].color;
//         cells[row + rowOffset][column + columnOffset].state = cells[row][column].state;
//         cells[row + rowOffset][column + columnOffset].updated = 1;
//         cells[row][column].state = EMPTY;
//         return true;
//     }
//     return false;
// }

// bool Grid::SwapCell(int row1, int row2, int column1, int column2) {
//     Cell cell1 = cells[row1][column1];
//     Cell cell2 = cells[row2][column2];
//     cell1.updated += 1;
//     cell2.updated += 1;
//     cells[row1][column1] = cell2;
//     cells[row2][column2] = cell1;
// }

