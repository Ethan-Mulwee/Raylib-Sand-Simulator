#include "grid.hpp"
#include "raylib.h"

void Grid::Draw(){
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            Color color;
            if (cells[row][column].state != EMPTY) {
                color = cells[row][column].color;
            } else {
                color = Color{55,55,55,255};
            }
            DrawRectangle(column*cellSize, row*cellSize, cellSize, cellSize, color);
        }
    }
}

void Grid::Set(int row, int column, Color color, Grid::State stateInput) {
    //if within bounds
    if (row < rows && row > -1 && column < columns && column > -1) {
        cells[row][column].color = color;
        cells[row][column].state = stateInput;
    }
}

void Grid::Step() {
    tempcells = std::vector<std::vector<cell>>(rows, std::vector<cell>(columns, cell(EMPTY)));
    for (int row = 0; row < rows; row++) {
        //TODO: Alternate loop direction
        for (int column = 0; column < columns; column++) {
            //Is cell empty?
            if (cells[row][column].state == EMPTY) continue;
            //Is cell at the bottom?
            if (row == rows-1) {
                SetCell(row, 0, column, 0);
                continue;
            }
            //Is the cell wood?
            if (cells[row][column].state == WOOD) {
                SetCell(row, 0, column, 0);
                continue;
            }
            //Is the cell below empty?
            if (cells[row+1][column].state == EMPTY && tempcells[row+1][column].state == EMPTY) {
                SetCell(row, 1, column, 0);
                continue;
            }
            //Is the cell water?
            if (cells[row][column].state == WATER) {
                if (GetRandomValue(0,1)) {
                    if (column != columns-1 && cells[row][column+1].state == EMPTY && tempcells[row][column+1].state == EMPTY) {
                        SetCell(row, 0, column, 1);
                        continue;
                    }
                    if (column != 0 && cells[row][column-1].state == EMPTY && tempcells[row][column-1].state == EMPTY) {
                        SetCell(row, 0, column, -1);
                        continue;
                    }
                } else {
                    if (column != 0 && cells[row][column-1].state == EMPTY && tempcells[row][column-1].state == EMPTY) {
                        SetCell(row, 0, column, -1);
                        continue;
                    }
                    if (column != columns-1 && cells[row][column+1].state == EMPTY && tempcells[row][column+1].state == EMPTY) {
                        SetCell(row, 0, column, 1);
                        continue;
                    }
                }
                SetCell(row, 0, column, 0);
                continue;
            }
            
            if (GetRandomValue(0,1)) {
                //Check right then left
                if (column != columns-1 && cells[row+1][column+1].state == EMPTY && tempcells[row+1][column+1].state == EMPTY) {
                    SetCell(row, 1, column, 1);
                    continue;
                }
                if (column != 0 && cells[row+1][column-1].state == EMPTY && tempcells[row+1][column-1].state == EMPTY) {
                    SetCell(row, 1, column, -1);
                    continue;
                }
            } 
            else {
                //Check left then right
                if (column != 0 && cells[row+1][column-1].state == EMPTY && tempcells[row+1][column-1].state == EMPTY) {
                    SetCell(row, 1, column, -1);
                    continue;
                }
                if (column != columns-1 && cells[row+1][column+1].state == EMPTY && tempcells[row+1][column+1].state == EMPTY) {
                    SetCell(row, 1, column, 1);
                    continue;
                }
            }
            //If no to all then the cell stays the same
            SetCell(row, 0, column, 0);
        }
    }
    cells = tempcells;
}

void Grid::SetCell(int row, int offsetRow, int column, int offsetColumn)
{
    tempcells[row + offsetRow][column + offsetColumn].color = cells[row][column].color;
    tempcells[row + offsetRow][column + offsetColumn].state = cells[row][column].state;
}
