#include <iostream>
#include <fstream>
#include <iomanip>
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
    cout << fixed << setprecision(3);
    while(getline(input, line)) {
        cout << stof(line) << endl;
    }

    return 0;
}
