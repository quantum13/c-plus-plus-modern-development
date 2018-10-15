#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Rational {
public:
    Rational() {
        _numerator = 0;
        _denomintator = 1;
    }

    Rational(int numerator, int denominator) {
        _numerator = numerator;
        _denomintator = denominator;
        _normalize();
    }

    int Numerator() const {
        return _numerator;
    }

    int Denominator() const {
        return _denomintator;
    }

    bool operator==(const Rational& r) const {
        return _numerator==r.Numerator() && _denomintator==r.Denominator();
    }

    bool operator<(const Rational& r) const {
        return _numerator * r.Denominator() < r.Numerator() * _denomintator;
    }

    Rational operator+(const Rational& r) const {
        return Rational{
            _numerator * r.Denominator() + r.Numerator() * _denomintator,
            _denomintator * r.Denominator()
        };
    }

    Rational operator-(const Rational& r) const {
        return Rational{
            _numerator * r.Denominator() - r.Numerator() * _denomintator,
            _denomintator * r.Denominator()
        };
    }

    Rational operator*(const Rational& r) const {
        return Rational{
            _numerator * r.Numerator(),
            _denomintator * r.Denominator()
        };
    }

    Rational operator/(const Rational& r) const {
        return Rational{
            _numerator * r.Denominator(),
            _denomintator * r.Numerator()
        };
    }

    friend ostream& operator<<(ostream& out, const Rational& r) {
        out << r.Numerator() << "/" << r.Denominator();
        return out;
    }

    friend istream& operator>>(istream& in, Rational& r) {
        int numerator, denominator;

        if ((in >> numerator) && (in.ignore(1)) && (in >> denominator)) {
            r.Update(numerator, denominator);
        }

        return in;
    }


    void Update(int new_numerator, int new_denominator) {
        _numerator = new_numerator;
        _denomintator = new_denominator;

        _normalize();
    }

private:
    int _numerator;
    int _denomintator;

    static int gcd(int a, int b) {
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

    void _normalize() {
        if (_numerator==0) {
            _denomintator = 1;
        } else if (_denomintator!=0) {
            int _gcd = gcd(_numerator, _denomintator);
            // cout << _gcd << endl;
            _numerator /= _gcd;
            _denomintator /= _gcd;
        }

        if (_denomintator < 0) {
            _numerator *= -1;
            _denomintator *= -1;
        }
    }
};

