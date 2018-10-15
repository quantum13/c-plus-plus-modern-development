#include <iostream>
#include "08.hpp"
using namespace std;


// Реализуйте для класса Rational операторы * и /

int main() {
    {
        Rational a(-4, 1000000);
        Rational b(0, -100000);
        Rational c = a * b;
        bool equal = c == Rational(0, 1);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
