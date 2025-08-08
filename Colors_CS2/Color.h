#pragma once
#include <iostream>

class Color {
public:
    int r, g, b;
    Color();
    Color(int rr, int gg, int bb);

    friend std::ostream& operator<<(std::ostream& os, const Color& c);
};
