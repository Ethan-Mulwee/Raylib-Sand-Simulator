#include <raylib.h>
#include "grid.hpp"
#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include "main.h"


int main()
{

    const int screenWidth = 1280;
    const int screenHeight = 720;
    const int gridScale = 10;
    Grid grid = Grid(72,128,gridScale);
    Grid::State state = Grid::State::SAND;
    

    InitWindow(screenWidth, screenHeight, "Sand Simulation");
    SetTargetFPS(200);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKGRAY);
        if (IsKeyPressed(KEY_ONE)) {
            state = Grid::State::SAND;
        }
        if (IsKeyPressed(KEY_TWO)) {
            state = Grid::State::WOOD;
        }
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            grid.Set(GetMouseY()/gridScale, GetMouseX()/gridScale, Color{(unsigned char)((sin(GetTime()*0.2)*50)+155),(unsigned char)((sin(GetTime()+540*0.05)*50)+155),(unsigned char)((sin(GetTime()+12305*0.1)*50)+155),255}, state);
        }
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