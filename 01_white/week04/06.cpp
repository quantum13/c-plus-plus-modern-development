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

    int y_max, x_max;
    input >> y_max >> x_max;

    string temp;
    getline(input, temp);

    for (int y=0; y<y_max; y++) {
        for (int x=0; x<x_max; x++) {
            getline(input, temp, (x==x_max-1 ? '\n' : ','));
            cout << setw(10) << temp << (x==x_max-1 ? "" : " ");
        }
        if (y<y_max-1) {
            cout << endl;
        }
    }

    return 0;
}
