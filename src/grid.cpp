#include "grid.hpp"
#include "raylib.h"

void Grid::Draw(){
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            Color color = cells[row][column].i ? cells[row][column].color : Color{55,55,55,255};
            DrawRectangle(column*cellSize, row*cellSize, cellSize, cellSize, color);
        }
    }
}

void Grid::Set(int row, int column, Color color) {
    //if within bounds
    if (row < rows && row > -1 && column < columns && column > -1) {
        cells[row][column].i = 1;
        cells[row][column].color = color;
    }
}

void Grid::Step() {
    std::vector<std::vector<cell>> tempcells = std::vector<std::vector<cell>>(rows, std::vector<cell>(columns, cell(0, SAND)));
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            //Is cell not sand?
            if (cells[row][column].i == 0) continue;
            //Is cell at the bottom?
            if (row == rows-1) {
                tempcells[row][column].i = 1;
                tempcells[row][column].color = cells[row][column].color;
                continue;
            }
            //Is the cell below empty?
            if (cells[row+1][column].i == 0) {
                tempcells[row+1][column].i = 1;
                tempcells[row+1][column].color = cells[row][column].color;
                continue;
            }
            if (GetRandomValue(0,1)) {
                //Check right then left
                if (column != columns-1 && cells[row+1][column+1].i == 0) {
                    tempcells[row+1][column+1].i = 1;
                    tempcells[row+1][column+1].color = cells[row][column].color;
                    continue;
                }
                if (column != 0 && cells[row+1][column-1].i == 0) {
                    tempcells[row+1][column-1].i = 1;
                    tempcells[row+1][column-1].color = cells[row][column].color;
                    continue;
                }
            } 
            else {
                //Check left then right
                if (column != 0 && cells[row+1][column-1].i == 0) {
                    tempcells[row+1][column-1].i = 1;
                    tempcells[row+1][column-1].color = cells[row][column].color;
                    continue;
                }
                if (column != columns-1 && cells[row+1][column+1].i == 0) {
                    tempcells[row+1][column+1].i = 1;
                    tempcells[row+1][column+1].color = cells[row][column].color;
                    continue;
                }
            }
            //If no to all then the cell stays the same
            tempcells[row][column].i = 1;
            tempcells[row][column].color = cells[row][column].color;
        }
    }
    cells = tempcells;
}