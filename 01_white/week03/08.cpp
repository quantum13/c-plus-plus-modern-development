#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>

using namespace std;

class Incognizable {
public:
    Incognizable() {}
    Incognizable(int a) {}
    Incognizable(int a, int b) {}
};

int main() {
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 1};
    return 0;
}

// !!
//struct Incognizable {
//    int x = 0;
//    int y = 0;
//};