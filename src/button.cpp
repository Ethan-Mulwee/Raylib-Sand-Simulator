#include "button.hpp"

bool Button::Check() {
    action = false;
    Vector2 mousePos = GetMousePosition();
    if (CheckCollisionPointRec(mousePos, bounds)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) state = 2;
        else state = 1;
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) action = true;
    }
    else {
        action = false;
        state = 0;
        return false;
    }
}

void Button::Draw(bool Highlight) {
    Color _color = color;
    if (state == 1) _color = ColorBrightness(_color, .2);
    if (state == 2) _color = ColorBrightness(_color, 0.5);
    if (Highlight) DrawRectangle(bounds.x-2, bounds.y-2, bounds.width+4, bounds.height+4, WHITE);
    DrawRectangleRec(bounds, _color);
    DrawText(text.c_str(), bounds.x+1, (bounds.y+bounds.height)*0.5, 0, WHITE);
}