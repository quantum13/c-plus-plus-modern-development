#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double n, a, b, x, y;
    cin >> n >> a >> b >> x >> y;

    if (n <= a) {
        cout << n;
    } else if (n <= b) {
        cout << n - n * x / 100.0;
    } else {
        cout << n - n * y / 100.0;
    }

    return 0;
}