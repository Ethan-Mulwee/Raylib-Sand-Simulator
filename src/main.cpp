#include <raylib.h>
#include "grid.hpp"
#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include "main.h"

int main()
{

    const int screenWidth = 2560;
    const int screenHeight = 1440;
    const int gridScale = 10;
    Grid grid = Grid(140,256,gridScale);
    
    std::string test = "Test";
    test.c_str();

    InitWindow(screenWidth, screenHeight, "Sand Simulation");
    SetTargetFPS(200);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKGRAY);
        grid.Set(GetMouseY()/gridScale, GetMouseX()/gridScale, Color{(unsigned char)((sin(GetTime()*0.4)*50)+155),160,20,255});
        grid.Step();
        grid.Draw();
        DebugText();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
void DebugText()
{
    DrawText(std::to_string(GetMouseX() / 10).c_str(), 10, 10, 10, WHITE);
    DrawText(std::to_string(GetMouseY() / 10).c_str(), 10, 20, 10, WHITE);
}