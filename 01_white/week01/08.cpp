#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int gcd(int a, int b) {
    if (a==0) return a;
    if (b==0) return b;
    if (a==b) return a;

    if (a==1 || b==1) return 1;

    if (a%b) {
        return gcd(b, a %b);
    } else {
        return b;
    }



}

int main() {
    int a, b;
    cin >> a >> b;

    if (a==b && b==0) {
        return 0;
    }



    cout << gcd(max(a, b), min(a, b));

    return 0;
}
