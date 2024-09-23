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
    SetTargetFPS(100);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKGRAY);
        if (IsKeyPressed(KEY_ZERO)) state = Grid::State::EMPTY;
        if (IsKeyPressed(KEY_ONE)) state = Grid::State::SAND;
        if (IsKeyPressed(KEY_TWO)) state = Grid::State::WOOD;
        if (IsKeyPressed(KEY_THREE)) state = Grid::State::WATER;
        if (IsKeyPressed(KEY_FOUR)) state = Grid::State::FIRE;
        Color color;
        double brightness;
        switch(state) {
            case Grid::State::SAND:
            brightness = GetRandomValue(95,100)*0.01;
            color = Color{(unsigned char)(((sin(GetTime()*0.2)*50)+155)*brightness),(unsigned char)(((sin(GetTime()+540*0.05)*50)+155)*brightness),(unsigned char)(((sin(GetTime()+12305*0.1)*50)+155)*brightness),255};
            break;
            case Grid::State::WOOD:
            brightness = (GetRandomValue(95,100)+((sin((GetTime()*0.1)))*0))*0.01;
            color = Color{(unsigned char)(50*brightness),(unsigned char)(30*brightness),(unsigned char)(15*brightness),255};
            break;
            case Grid::State::WATER:
            brightness = (GetRandomValue(90,100)+((sin((GetTime()*0.1)))*0))*0.01;
            color = Color{(unsigned char)(10*brightness),(unsigned char)(80*brightness),(unsigned char)(180*brightness),100};
            break;
            case Grid::State::FIRE:
            color = Color{200,120,10,255};
            break;
        }
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            int x = GetMouseX()/gridScale;
            int y = GetMouseY()/gridScale; 
            grid.Set(y, x, color, state);
            grid.Set(y+1, x, color, state);
            grid.Set(y-1, x, color, state);
            grid.Set(y, x+1, color, state);
            grid.Set(y, x-1, color, state);
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
    DrawText(("Mouse X: " + std::to_string(GetMouseX() / 10)).c_str(), 10, 10, 10, WHITE);
    DrawText(("Mouse Y: " + std::to_string(GetMouseY() / 10)).c_str(), 10, 20, 10, WHITE);
}