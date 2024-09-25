#include <raylib.h>
#include "simulation.hpp"
#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include <memory>


int main()
{
    const int screenWidth = 1280;
    const int screenHeight = 720;
    const int gridScale = 10;
    IntializeGrid(72, 128);
    cellSize = gridScale;
    

    InitWindow(screenWidth, screenHeight, "Sand Simulation");
    SetTargetFPS(100);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKGRAY);
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            int x = GetMouseX()/gridScale;
            int y = GetMouseY()/gridScale; 
            Set(y, x, std::make_shared<Sand>(WHITE));
        }
        Step();
        Draw();
        DebugText();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
void DebugText()
{
    DrawText(("Mouse X: " + std::to_string(GetMouseX() / 10)).c_str(), 10, 10, 10, WHITE);
    DrawText(("Mouse Y: " + std::to_string(GetMouseY() / 10)).c_str(), 10, 20, 10, WHITE);
}