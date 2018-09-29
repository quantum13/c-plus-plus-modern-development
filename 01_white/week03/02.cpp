#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>

using namespace std;


int main() {
    int size;

    cin >> size;

    vector<string> strings;

    for(int i=0; i<size; i++) {
        string num;
        cin >> num;
        strings.push_back(num);
    }

    sort(begin(strings), end(strings), [](const string &a, const string &b) {
        string x=a, y=b;
        transform(x.begin(), x.end(), x.begin(), ::tolower);
        transform(y.begin(), y.end(), y.begin(), ::tolower);
        return x < y;
    });

    for(const auto &n : strings) {
        cout << n << " ";
    }

}
