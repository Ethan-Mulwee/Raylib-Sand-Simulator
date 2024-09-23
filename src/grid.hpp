#pragma once
#include <vector>
#include "raylib.h"

class Grid {
    public:
        Grid(int rows, int columns, int cellSize)
        : rows(rows), columns(columns), cellSize(cellSize), cells(rows, std::vector<cell>(columns, cell(EMPTY))){};
        typedef enum {EMPTY, SAND, WOOD, WATER, FIRE, SMOKE} State;
        struct cell {
            Color color = Color{0,0,0,255};
            State state;
            int updated = 0;
            cell(State inputState) {
                state = inputState;
            }
            void clear() {
                updated = 0;
            }
            void update() {

            }
        };
        void Draw();
        void Set(int row, int column, Color color, State stateInput);
        void Step();
        bool CheckEmpty(int row, int rowOffset, int column, int columnOffset);
        bool MoveCell(int row, int rowOffset, int column, int columnOffset);
        void Swap(cell* a, cell* b);
        bool CheckCell(int row, int rowOffset, int column, int columnOffset, Grid::State stateInput);
        //Function should return an array of pointers to the neighbors
        //so all neighbors can be chcked more easily without having to copy them or reference them directly like
        //cells[row+i][column+j] where i and j range from -1 to 1
        //&cell[] GetNeighbors(int row, int column);

    private:
        int rows;
        int columns;
        int cellSize;
        std::vector<std::vector<cell>> cells;
        std::vector<std::vector<cell>> tempcells;
};
