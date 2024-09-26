#include "UI.hpp"
#include <vector>

void UI::append()
{
    //buttons.push_back()
}

void UI::Draw()
{
    for (int i  =0; i < buttons.size(); i++) {
        bool _Highlight = false;
        if (i == Selected) _Highlight = true;
        buttons[i].Draw(_Highlight);
    }
}

void UI::Check()
{
    UIHover = false;
    for (int i = 0; i < buttons.size(); i++) {
        buttons[i].Check();
        if (buttons[i].action) Selected = i;
        UIHover = UIHover || (buttons[i].state >= 1);
    }
}
