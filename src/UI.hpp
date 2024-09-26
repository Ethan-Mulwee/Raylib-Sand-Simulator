#pragma once
#include "button.hpp"
#include <vector>

class UI {
    public:
    std::vector<Button> buttons;
    bool UIHover;
    int Selected;
    void append();
    void Draw();
    void Check();
};