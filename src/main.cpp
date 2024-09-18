#include <raylib.h>
#include "grid.hpp"

int main()
{

    const int screenWidth = 800;
    const int screenHeight = 600;
    Grid grid = Grid(60,80,10);
    grid.Set(4,4);

    InitWindow(screenWidth, screenHeight, "Sand Simulation");
    SetTargetFPS(2);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        grid.Step();
        //grid.Set(GetMouseX()/10,GetMouseY()/10);
        grid.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}