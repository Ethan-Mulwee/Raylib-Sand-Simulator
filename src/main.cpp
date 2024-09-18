#include <raylib.h>
#include "grid.hpp"

int main()
{

    const int screenWidth = 800;
    const int screenHeight = 600;
    Grid grid = Grid(10,10,10);
    grid.Set(4,4);

    InitWindow(screenWidth, screenHeight, "Sand Simulation");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        grid.Draw();
        DrawText("test", 100, 100, 20, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}