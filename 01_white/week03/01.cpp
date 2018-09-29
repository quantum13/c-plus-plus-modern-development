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

    vector<int> nums;

    for(int i=0; i<size; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    sort(begin(nums), end(nums), [](const int &x, const int &y) { return abs(x) < abs(y);});

    for(auto n : nums) {
        cout << n << " ";
    }

}
