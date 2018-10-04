#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>

using namespace std;

int main() {
    ifstream input("input.txt");
    string line;
    while(getline(input, line)) {
        cout << line << endl;
    }

    return 0;
}
