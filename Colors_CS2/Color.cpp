#include "Color.h"

Color::Color() : r(255), g(255), b(255) {}
Color::Color(int rr, int gg, int bb) : r(rr), g(gg), b(bb) {}

std::ostream& operator<<(std::ostream& os, const Color& c) {
    // Equal cases first
    if (c.r == c.g && c.g == c.b) {
        if (c.r > 250) return os << 'W';
        if (c.r < 50)  return os << 'D';
        return os << 'G';
    }
    // Ties of two
    if (c.r == c.b && c.r > c.g) return os << 'P';
    if (c.r == c.g && c.r > c.b) return os << 'Y';
    if (c.g == c.b && c.g > c.r) return os << 'T';

    // Single max
    if (c.r > c.g && c.r > c.b) return os << 'R';
    if (c.g > c.r && c.g > c.b) return os << 'V';
    return os << 'B';
}
