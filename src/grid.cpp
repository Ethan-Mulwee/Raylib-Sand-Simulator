#include "grid.hpp"
#include "raylib.h"

void Grid::Draw(){
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            Color color = cells[row][column] ? Color{255,255,255,255} : Color{55,55,55,255};
            DrawRectangle(column*cellSize, row*cellSize, cellSize, cellSize, color);
        }
    }
}

void Grid::Set(int row, int column) {
    cells[row][column] = 1;
}

void Grid::Step() {
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            int cell = cells[row][column];
            if (row-1 < 0) return;
            if (cell != 0 && cells[row-1][column] == 0) {
                cells[row][column] = 0;
                cells[row-1][column] = 1;
            }
        }
    }
}