#include "button.hpp"

bool Button::Check() {
    Vector2 mousePos = GetMousePosition();
    if (CheckCollisionPointRec(mousePos, bounds)) {
        UIHover = true;
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) state = 2;
        else state = 1;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) return true;
    }
    else {
        UIHover = false;
        state = 0;
        return false;
    }
}

void Button::Draw() {
    Color _color = color;
    if (state == 1) _color = ColorBrightness(_color, .2);
    if (state == 2) _color = ColorBrightness(_color, 0.5);
    DrawRectangleRec(bounds, _color);
}