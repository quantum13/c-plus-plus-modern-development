#include <iostream>
#include <string>

using namespace std;

int main() {
    string x, y, z;
    std::cin >> x >> y >> z;

    std::cout <<
        (
            x < y
                ? (z < x ? z : x)
                : (z < y ? z : y)
        );

    return 0;
}