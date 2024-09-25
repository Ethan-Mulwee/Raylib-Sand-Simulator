#pragma once
#include <vector>
#include <memory>
#include "raylib.h"

class Grid {
    public:
        class Cell
        {
            public:
            Color color = Color{0,0,0,255};
            bool empty = false;

            virtual ~Cell() {}
            Cell() {}
            Cell(Color colorI, bool emptyI) {color = colorI; empty = emptyI;}

            virtual void update() {
                
            }
        };

        class Sand : public Cell {
            public:
            Sand(Color colorI) {color = colorI;}
            void update() {
                color = Color{255,255,255,255};
            }
        };
        Grid(int rows, int columns, int cellSize)
        : rows(rows), columns(columns), cellSize(cellSize), cells(rows, std::vector<std::shared_ptr<Cell>>(columns, std::make_shared<Cell>(BLACK, true))){};
        void Draw();
        void Set(int row, int column, std::shared_ptr<Cell> celltype);
        void Step();
        // bool CheckEmpty(int row, int rowOffset, int column, int columnOffset);
        // bool MoveCell(int row, int rowOffset, int column, int columnOffset);
        // bool SwapCell(int row1, int row2, int column1, int column2);
        // bool CheckCell(int row, int rowOffset, int column, int columnOffset, Grid::State stateInput);

    private:
        int rows;
        int columns;
        int cellSize;
        std::vector<std::vector<std::shared_ptr<Cell>>> cells;
};

// class Behavior {
//     public:
//     Behavior() {}
//     virtual void update() {

//     }
// };

// class GoesDown : public Behavior {
//     public:
//     GoesDown() {}
//     void update() {

//     }
// };
