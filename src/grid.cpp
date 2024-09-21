#include "grid.hpp"
#include "raylib.h"
#include "stdio.h"

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
            //Is the cell wood?
            if (cells[row][column].state == WOOD) {
                SetCell(row, 0, column, 0);
                continue;
            }
            //Is the cell below empty?
            if (CheckCell(row, 1, column, 0, EMPTY))
            {
                SetCell(row, 1, column, 0);
                continue;
            }
            //Is the cell water?
            if (cells[row][column].state == WATER) {
                int a, b;
                if (GetRandomValue(0,1)) { a = 1; b = -1;}
                else { a = -1; b = 1;} 
                if (cells[row][column+a].state == EMPTY && tempcells[row][column+a].state == EMPTY) {
                    if (SetCell(row, 0, column, a)) continue;
                }
                if (cells[row][column+b].state == EMPTY && tempcells[row][column+b].state == EMPTY) {
                    if (SetCell(row, 0, column, b)) continue;
                }
                SetCell(row, 0, column, 0);
                continue;
            }
            
            int a, b;
            if (GetRandomValue(0,1)) { a = 1; b = -1;}
            else { a = -1; b = 1;} 
            if (CheckCell(row, 1, column, a, EMPTY)) {
                if (SetCell(row, 1, column, a)) continue;
            }
            if (CheckCell(row, 1, column, b, EMPTY)) {
                if (SetCell(row, 1, column, b)) continue;
            }
            //If no to all then the cell stays the same
            SetCell(row, 0, column, 0);
        }
    }
    cells = tempcells;
}

bool Grid::CheckCell(int row, int rowOffset, int column, int columnOffset, Grid::State checkState)
{
    if (column+columnOffset < columns && column+columnOffset >= 0 && row + rowOffset < rows && row+rowOffset >= 0) {
        return cells[row + rowOffset][column + columnOffset].state == checkState && tempcells[row + rowOffset][column + columnOffset].state == checkState;
    }
    return false;
}

//Return true if in bounds and false if out of bounds
bool Grid::SetCell(int row, int rowOffset, int column, int columnOffset)
{
    if (column+columnOffset < columns && column+columnOffset >= 0 && row + rowOffset < rows && row+rowOffset >= 0) {
        tempcells[row + rowOffset][column + columnOffset].color = cells[row][column].color;
        tempcells[row + rowOffset][column + columnOffset].state = cells[row][column].state;
        return true;
    }
    return false;
}
