#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int res = -2;
    for (int i =0; i<s.length(); i++) {
        if (s[i] != 'f') continue;

        if (res == -2) {
            res = -1;
            continue;
        }

        if (res == -1) {
            res = i;
            break;
        }
    }

    cout << res;

    return 0;
}