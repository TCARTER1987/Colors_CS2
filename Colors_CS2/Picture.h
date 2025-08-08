#pragma once
#include <vector>
#include "Color.h"

class Picture {
    int width, height;
    std::vector<std::vector<Color>> pixels;
public:
    Picture(int w, int h);

    void setPixel(int x, int y, const Color& c);
    int getWidth() const;
    int getHeight() const;

    friend std::ostream& operator<<(std::ostream& os, const Picture& pic);
};
