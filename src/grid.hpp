#pragma once
#include <vector>
#include "raylib.h"

class Grid {
    public:
        Grid(int rows, int columns, int cellSize)
        : rows(rows), columns(columns), cellSize(cellSize), cells(rows, std::vector<cell>(columns, cell(0, SAND))){};
        typedef enum {SAND, WOOD} State;
        void Draw();
        void Set(int row, int column, Color color, State stateInput);
        void Step();
    private:
        int rows;
        int columns;
        int cellSize;
        struct  cell
        {
            int i = 0;
            Color color;
            State state;
            cell(int input, State inputState) {
                i = input;
                state = inputState;
            }
        };
        std::vector<std::vector<cell>> cells;
};