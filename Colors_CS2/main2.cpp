#include <iostream>
#include <string>
#include "EaterOf.h"
using namespace std;

int main() {
    EaterOf<int> intEater;
    EaterOf<double> doubleEater;
    EaterOf<string> stringEater;


    intEater.eat(5);
    doubleEater.eat(5.5);
    stringEater.eat("5"s);

    cout << "Int burp: " << intEater.burp() << endl;
    cout << "Double burp: " << doubleEater.burp() << endl;
    cout << "String burp: " << stringEater.burp() << endl;

    return 0;
}
