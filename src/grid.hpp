#pragma once
#include <vector>
#include "raylib.h"

class Grid {
    public:
        Grid(int rows, int columns, int cellSize)
        : rows(rows), columns(columns), cellSize(cellSize), cells(rows, std::vector<cell>(columns, cell(EMPTY))){};
        typedef enum {EMPTY, SAND, WOOD, WATER} State;
        void Draw();
        void Set(int row, int column, Color color, State stateInput);
        void Step();
        bool CheckCell(int row, int rowOffset, int column, int columnOffset, Grid::State checkState);
        bool SetCell(int row, int rowOffset, int column, int columnOffset);

    private:
        int rows;
        int columns;
        int cellSize;
        struct cell
        {
            Color color = Color{0,0,0,255};
            State state;
            cell(State inputState) {
                state = inputState;
            }
        };
        std::vector<std::vector<cell>> cells;
        std::vector<std::vector<cell>> tempcells;
};