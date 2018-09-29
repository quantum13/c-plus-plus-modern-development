#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


int main() {
    int size;
    cin >> size;

    vector<int> v(size);

    for(int i=0; i<size; i++) {
        cin >> v[i];
    }

    int avg = accumulate(begin(v), end(v), 0) / size;

    string res = "";
    int cnt = 0;
    for(int  i=0; i<size; i++) {
        if (v[i] > avg) {
            res += to_string(i) + " ";
            cnt++;
        }
    }

    cout << cnt << endl << res;
}

