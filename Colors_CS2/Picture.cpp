#include "Picture.h"

Picture::Picture(int w, int h) : width(w), height(h),
pixels(h, std::vector<Color>(w, Color(255, 255, 255))) {
}

void Picture::setPixel(int x, int y, const Color& c) {
    if (x < 0 || y < 0 || x >= width || y >= height) return;
    pixels[y][x] = c;
}

int Picture::getWidth() const { return width; }
int Picture::getHeight() const { return height; }

std::ostream& operator<<(std::ostream& os, const Picture& pic) {
    for (int y = 0; y < pic.height; ++y) {
        for (int x = 0; x < pic.width; ++x) {
            os << pic.pixels[y][x];
        }
        os << '\n';
    }
    return os;
}
