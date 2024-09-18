#include <raylib.h>
#include "grid.hpp"
#include <string>
#include <iostream>
#include <bits/stdc++.h>

int main()
{

    const int screenWidth = 800;
    const int screenHeight = 600;
    Grid grid = Grid(60,80,10);
    grid.Set(4,4);
    
    std::string test = "Test";
    test.c_str();

    InitWindow(screenWidth, screenHeight, "Sand Simulation");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKGRAY);
        grid.Step();
        grid.Draw();
        DrawRectangle(GetMouseX(), GetMouseY(), 10, 10, WHITE);
        DrawText(std::to_string(GetMouseX()).c_str(), 10, 10, 10, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}