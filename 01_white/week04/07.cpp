#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>

using namespace std;

struct Student {
    string first_name;
    string last_name;
    int birth_day{0};
    int birth_month{0};
    int birth_year{0};
};

vector<Student> students;


int main() {
    // ifstream input("input.txt");

    int count;
    cin >> count;

    for (int y=0; y<count; y++) {
        Student s;
        cin >> s.first_name >> s.last_name >> s.birth_day >> s.birth_month >> s.birth_year;
        students.push_back(s);
    }

    cin >> count;
    for (int y=0; y<count; y++) {
        string cmd;
        int num;
        cin >> cmd >> num;

        if (num > students.size() || num <= 0) {
            cout << "bad request" << endl;
            continue;
        }

        if (cmd == "name") {
            cout << students[num-1].first_name << " " << students[num-1].last_name << endl;
        } else if (cmd == "date") {
            cout << students[num-1].birth_day << "." << students[num-1].birth_month
                << "." << students[num-1].birth_year << endl;
        } else {
            cout << "bad request" << endl;
            continue;
        }
    }

    return 0;
}
