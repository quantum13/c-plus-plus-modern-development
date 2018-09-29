#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Reversed(const vector<int>& v) {
    vector<int> x;
    x = v;
    reverse(begin(x), end(x));
    return x;
}


int main() {
    return 0;
}

