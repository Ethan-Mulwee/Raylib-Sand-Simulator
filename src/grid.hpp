#pragma once
#include <vector>
#include <memory>
#include "raylib.h"

class Grid {
    public:
        class Cell
        {
            public:
            Cell() {}
            virtual ~Cell() {}
            Cell(Color colorI, bool emptyI) {color = colorI; empty = emptyI;}
            Color color = Color{0,0,0,255};
            bool empty = false;

            virtual void update(Grid* grid, int row, int column) {}
        };

        class Sand : public Cell {
            public:
            Sand(Color colorI) {color = colorI;}
            void update(Grid* grid, int row, int column);
        };
        Grid(int rows, int columns, int cellSize)
        : rows(rows), columns(columns), cellSize(cellSize), cells(rows, std::vector<std::shared_ptr<Cell>>(columns, std::make_shared<Cell>(BLACK, true))){};
        void Draw();
        void Set(int row, int column, std::shared_ptr<Cell> celltype);
        void Step();
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
