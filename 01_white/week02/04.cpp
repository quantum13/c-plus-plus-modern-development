#include <iostream>
#include <string>
#include <cmath>
#include <vector>
// #include <boost/algorithm/string/join.hpp>

using namespace std;


void UpdateIfGreater(int first, int& second) {
    if (first > second) {
        second = first;
    }
}


int main() {
    int a, b;

    cin >> a >> b;

    UpdateIfGreater(a, b);

    cout << a << " " << b;

    return 0;
}
