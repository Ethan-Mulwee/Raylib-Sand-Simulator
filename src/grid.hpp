#pragma once
#include <vector>
#include <memory>
#include "raylib.h"

class Grid {
    public:
        Grid(int rows, int columns, int cellSize)
        : rows(rows), columns(columns), cellSize(cellSize), cells(rows, std::vector<cell>(columns, cell(EMPTY))){};
        void Draw();
        void Set(int row, int column, Color color, State stateInput);
        void Step();
        bool CheckEmpty(int row, int rowOffset, int column, int columnOffset);
        bool MoveCell(int row, int rowOffset, int column, int columnOffset);
        bool SwapCell(int row1, int row2, int column1, int column2);
        bool CheckCell(int row, int rowOffset, int column, int columnOffset, Grid::State stateInput);
        //Function should return an array of pointers to the neighbors
        //so all neighbors can be chcked more easily without having to copy them or reference them directly like
        //cells[row+i][column+j] where i and j range from -1 to 1
        //&cell[] GetNeighbors(int row, int column);

    private:
        int rows;
        int columns;
        int cellSize;
        std::vector<std::vector<std::shared_ptr<cell>>> cells;
};
class cell
{
    public:
    virtual ~cell() {}
    cell(Color colorI) {color = colorI;}
    Color color = Color{0,0,0,255};
    int update = 0;
    virtual void update() {
        
    }
};

class sand : public cell {
    public:
    void update() {
        color = WHITE;
    }
};