#pragma once
#include <vector>
#include <memory>
#include "raylib.h"

std::vector<std::vector<std::shared_ptr<Cell>>> cells;
int rows;
int columns;
int cellSize;

void IntializeGrid(int rows, int columns) {
    cells = std::vector<rows, std::vector<columns, std::make_shared<Cell>(BLACK, true)>>
};

class Cell
{
    public:
    Cell() {}
    virtual ~Cell() {}
    Cell(Color colorI, bool emptyI) {color = colorI; empty = emptyI;}
    Color color = Color{0,0,0,255};
    bool empty = false;

    virtual void update(int row, int column) {}
};

class Sand : public Cell {
    public:
    Sand(Color colorI) {color = colorI;}
    void update(int row, int column);
};

void Draw();
void Set(int row, int column, std::shared_ptr<Cell> celltype);
void Step();
void Swap();
