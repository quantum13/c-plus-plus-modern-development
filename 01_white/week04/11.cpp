#include <iostream>
#include <exception>
#include "08.hpp"
using namespace std;





// Вставьте сюда реализацию operator / для класса Rational

int main() {
    Rational first, second;
    char op;

    try {
        cin >> first >> op >> second;
    } catch (invalid_argument&) {
        cout << "Invalid argument";
        return 0;
    }

    switch (op) {
        case '+':
            cout << first + second;
            break;
        case '-':
            cout << first - second;
            break;
        case '*':
            cout << first * second;
            break;
        case '/':
            try {
                cout << first / second;
            } catch (domain_error&) {
                cout << "Division by zero";
            }
    }


    return 0;
}
