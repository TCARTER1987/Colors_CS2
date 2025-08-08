#pragma once
#include <iostream>
using namespace std;

template <typename T>
class EaterOf {
private:
    T sum;
public:
    EaterOf() : sum(T()) {}

    void eat(T food) {
        cout << "nom-nom" << endl;
        sum = sum + food;
    }

    T burp() {
        return sum;
    }
};
