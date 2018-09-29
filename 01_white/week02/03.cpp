#include <iostream>
#include <string>
#include <cmath>
#include <vector>
// #include <boost/algorithm/string/join.hpp>

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

vector<string> PalindromFilter( vector<string> words, int minLength) {
    vector<string> res;

    for (auto w : words) {
        if (w.length()>=minLength && IsPalindrom(w)) {
            res.push_back(w);
        }
    }

    return res;
}

int main() {
    vector<string> res = {"weew", "bro", "code"};

    // cout << boost::algorithm::join(PalindromFilter(res, 4), ", ");

    return 0;
}
