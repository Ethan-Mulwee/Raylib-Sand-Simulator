#pragma once
#include <raylib.h>
#include <string>

class Button {
    public:
    Button(float width, float height, float Xpos, float Ypos, Color color, std::string text)
    : width(width), height(height), Xpos(Xpos), Ypos(Ypos), color(color), text(text) {
        bounds = {Xpos, Ypos, width, height};
        state = 0; action = false;
    };
    bool Check();
    void Draw(bool Highlight);
    int state;
    bool action;
    private:
    float width, height, Xpos, Ypos;
    Rectangle bounds;
    Color color;
    std::string text;
};