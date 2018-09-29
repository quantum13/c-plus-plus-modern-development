#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


bool IsPalindrom(string val) {
    if (val.empty()) {
        return true;
    }

    for(unsigned long i=0, j=val.length()-1; i<j; i++, j--) {
        if (tolower(val[i]) != tolower(val[j])) {
            return false;
        }
    }

    return true;
}

int main() {
    string a;
    cin >> a;

    cout << IsPalindrom("");

    return 0;
}
