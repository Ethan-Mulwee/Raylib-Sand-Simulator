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
        int column; 
        if (row % 2 == 0) column = 0;
        else column = columns-1;
        while (true) {
            int a, b;
            switch (cells[row][column].state) {
                case EMPTY:
                    goto next;

                case WOOD:
                    SetCell(row, 0, column, 0);
                    goto next;

                case WATER:
                    if (CheckEmpty(row, 1, column, 0)) {SetCell(row, 1, column, 0); goto next;}
                    if (GetRandomValue(0,1)) { a = 1; b = -1;} else { a = -1; b = 1;} 
                    if (CheckEmpty(row, 0, column, a)) {SetCell(row, 0, column, a); goto next;}
                    if (CheckEmpty(row, 0, column, b)) {SetCell(row, 0, column, b); goto next;}
                    SetCell(row, 0, column, 0); goto next;

                case SAND:
                    if (CheckEmpty(row, 1, column, 0)) {SetCell(row, 1, column, 0); goto next;}
                    if (GetRandomValue(0,1)) { a = 1; b = -1;}
                    else { a = -1; b = 1;} 
                    if (CheckEmpty(row, 1, column, a)) {SetCell(row, 1, column, a); goto next;}
                    if (CheckEmpty(row, 1, column, b)) {if (SetCell(row, 1, column, b)) goto next;}
                    SetCell(row, 0, column, 0); goto next;
            }
            next:
            if (row % 2 == 0) {
                column++;
                if (column >= columns) break;
            }
            else {
                column--;
                if (column < 0) break;
            }
        }
    }
    cells = tempcells;
}

bool Grid::CheckEmpty(int row, int rowOffset, int column, int columnOffset)
{
    if (column+columnOffset < columns && column+columnOffset >= 0 && row + rowOffset < rows && row+rowOffset >= 0) {
        return cells[row + rowOffset][column + columnOffset].state == EMPTY && tempcells[row + rowOffset][column + columnOffset].state == EMPTY;
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
