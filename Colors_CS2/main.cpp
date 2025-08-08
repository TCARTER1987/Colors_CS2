#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <string>
#include "Color.h"
#include "Picture.h"
#include "Exceptions.h"

using namespace std;

static inline int clampWithLog(const char* name, int x, int minv, int maxv, int X, int Y) {
    if (x < minv) {
        try { throw ColorVectorOutOfRangeException(); }
        catch (const ColorVectorOutOfRangeException&) {
            cout << "Error! X: " << X << " Y: " << Y << " " << name
                << " value too low: min : " << minv << ", actual: " << x << ".\n";
        }
        return minv;
    }
    if (x > maxv) {
        try { throw ColorVectorOutOfRangeException(); }
        catch (const ColorVectorOutOfRangeException&) {
            cout << "Error! X: " << X << " Y: " << Y << " " << name
                << " value too high: max : " << maxv << ", actual: " << x << ".\n";
        }
        return maxv;
    }
    return x;
}

Picture loadPictureFromFile(const string& filename) {
    ifstream fin(filename);
    if (!fin) throw FileNotFoundException();

    vector<tuple<int, int, int, int, int>> entries;
    int maxX = -1, maxY = -1;

    while (true) {
        int X, Y, R, G, B;
        if (fin >> X >> Y >> R >> G >> B) {
            if (X < 0 || Y < 0) {
                try { throw CoordinateOutOfRangeException(); }
                catch (const CoordinateOutOfRangeException& e) {
                    cout << "Coordinate error: " << e.what()
                        << " (X: " << X << ", Y: " << Y << "). Skipping.\n";
                }
                continue;
            }

            R = clampWithLog("Red", R, 0, 255, X, Y);
            G = clampWithLog("Green", G, 0, 255, X, Y);
            B = clampWithLog("Blue", B, 0, 255, X, Y);

            entries.emplace_back(X, Y, R, G, B);
            if (X > maxX) maxX = X;
            if (Y > maxY) maxY = Y;
        }
        else {
            if (!fin.eof()) throw ColorFileFormatException();
            break;
        }
    }

    int width = max(1, maxX + 1);
    int height = max(1, maxY + 1);
    Picture pic(width, height);

    for (auto& e : entries) {
        int X, Y, R, G, B;
        tie(X, Y, R, G, B) = e;
        pic.setPixel(X, Y, Color(R, G, B));
    }

    return pic;
}

int main(int argc, char** argv) {
    string filename = (argc > 1 ? argv[1] : "colors.txt");

    try {
        Picture pic = loadPictureFromFile(filename);
        cout << pic;
    }
    catch (const FileNotFoundException& e) {
        cerr << "File error: " << e.what() << " (" << filename << ")\n";
    }
    catch (const ColorFileFormatException& e) {
        cerr << "Format error: " << e.what() << "\n";
    }
    catch (const exception& e) {
        cerr << "Unexpected error: " << e.what() << "\n";
    }
}
