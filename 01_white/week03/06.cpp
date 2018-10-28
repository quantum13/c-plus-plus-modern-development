#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>

using namespace std;

class ReversibleString {
public:
    ReversibleString() {}
    ReversibleString(string str) {
        _str = str;
    }

    string ToString() const {
        return _str;
    }

    void Reverse() {
        reverse(_str.begin(), _str.end());
    }

private:
    string _str;
};

int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}