#pragma once
#include <vector>

class Grid {
    public:
        Grid(int rows, int columns, int cellSize)
        : rows(rows), columns(columns), cellSize(cellSize), cells(rows, std::vector<int>(columns, 0)){};
        void Draw();
        void Set(int row, int column);
        void Step();
    private:
    int rows;
    int columns;
    int cellSize;
    std::vector<std::vector<int>> cells;
};