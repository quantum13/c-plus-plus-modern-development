#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(string s) {
    map<char, int> res;
    for(auto c: s) {
        res[c]++;
    }
    return res;
}

int main() {
    int size;

    cin >> size;

    string a, b;
    for(int i=0; i<size; i++) {
        cin >> a >> b;
        if (BuildCharCounters(a) == BuildCharCounters(b)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

}

