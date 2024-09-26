#pragma once
#include <raylib.h>

class Button {
    public:
    Button(float width, float height, float Xpos, float Ypos, Color color)
    : width(width), height(height), Xpos(Xpos), Ypos(Ypos), color(color){
        bounds = {Xpos, Ypos, width, height};
        state = 0; action = false;
    };
    bool Check();
    void Draw();
    bool UIHover;
    private:
    float width, height, Xpos, Ypos;
    Rectangle bounds;
    int state;
    bool action;
    Color color;
};