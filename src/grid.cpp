#include "grid.hpp"
#include "raylib.h"

void Grid::Draw(){
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            Color color = cells[row][column] ? Color{255,255,255,255} : Color{55,55,55,255};
            DrawRectangle(column*cellSize, row*cellSize, cellSize-1, cellSize-1, color);
        }
    }
}

void Grid::Set(int row, int column) {
    //if within bounds
    if (row < rows && row > -1 && column < columns && column > -1) {
        cells[row][column] = 1;
    }
}

void Grid::Step() {
    std::vector<std::vector<int>> tempcells = std::vector<std::vector<int>>(rows, std::vector<int>(columns, 0));
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            //Is cell not sand?
            if (cells[row][column] == 0) continue;
            //Is cell at the bottom?
            if (row == rows-1) {
                tempcells[row][column] = 1;
                continue;
            }
            //Is the cell below empty?
            if (cells[row+1][column] == 0) {
                tempcells[row+1][column] = 1;
                continue;
            }
            //If no to all then the cell stays the same
            tempcells[row][column] = 1;

        }
    }
    cells = tempcells;
}