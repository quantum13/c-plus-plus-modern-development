#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int a;
    cin >> a;

    vector<int16_t> res;

    while (a) {
        res.push_back(a%2);
        a /=2;
    }

    reverse(begin(res), end(res));

    for (auto c : res) {
        cout << c;
    }

    return 0;
}
