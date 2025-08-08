#include <iostream>
#include "PrimeFactors.h"
using namespace std;

int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;

    vector<int> factors = getPrimeFactors(num);

    cout << "Prime factors of " << num << ": ";
    for (int f : factors) {
        cout << f << " ";
    }
    cout << endl;

    return 0;
}
