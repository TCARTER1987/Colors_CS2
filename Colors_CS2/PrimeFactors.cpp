#include "PrimeFactors.h"

int findLowestPrimeFactor(int num) {
    if (num <= 3) return 0;

    for (int i = 2; i < num; i++) {
        if (num % i == 0) {

            return i;
        }
    }
    return 0;
}

vector<int> getPrimeFactors(int num) {
    vector<int> factors;
    if (num <= 1) return factors;

    int lowest = findLowestPrimeFactor(num);
    if (lowest == 0) {

        factors.push_back(num);
    }
    else {

        factors.push_back(lowest);
        vector<int> rest = getPrimeFactors(num / lowest);
        factors.insert(factors.end(), rest.begin(), rest.end());
    }
    return factors;
}
