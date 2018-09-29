#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


int Factorial(int val) {
    if (val == 1) {
        return 1;
    }
    if (val <= 0) {
        return 1;
    }

    return val * Factorial(val-1);
}

int main() {
    int a;
    cin >> a;


    cout << Factorial(a);

    return 0;
}
