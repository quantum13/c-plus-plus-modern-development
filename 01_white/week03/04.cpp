#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        _first_names[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        _last_names[year] = last_name;
    }
    string GetFullName(int year) {
        string first_name;
        string last_name;

        for (auto iter = _first_names.rbegin(); iter != _first_names.rend(); ++iter) {
            if (iter->first > year) {
                continue;
            }

            first_name = iter->second;
            break;
        }

        for (auto iter = _last_names.rbegin(); iter != _last_names.rend(); ++iter) {
            if (iter->first > year) {
                continue;
            }

            last_name = iter->second;
            break;
        }

        if (first_name.empty() && last_name.empty()) {
            return "Incognito";
        }

        if (first_name.empty()) {
            return last_name + " with unknown first name";
        }

        if (last_name.empty()) {
            return first_name+ " with unknown last name";
        }

        return first_name + " " + last_name;
    }
private:
    map<int, string> _first_names;
    map<int, string> _last_names;
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}
