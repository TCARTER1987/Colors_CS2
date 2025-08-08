#pragma once
#include <exception>

class FileNotFoundException : public std::exception {
public:
    const char* what() const noexcept override {
        return "File not found.";
    }
};

class ColorFileFormatException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Color file format error (expected: X Y R G B per line).";
    }
};

class CoordinateOutOfRangeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Coordinate out of range (negative X or Y).";
    }
};

class ColorVectorOutOfRangeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Color component out of range (expected 0..255).";
    }
};
