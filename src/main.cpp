#include <raylib.h>

int main()
{

    const int screenWidth = 800;
    const int screenHeight = 600;
    int Grid[10][10];
    //std::string s = "10";
    //int i = std::stoi(s);

    InitWindow(screenWidth, screenHeight, "Sand Simulation");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("test", 100, 100, 20, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}