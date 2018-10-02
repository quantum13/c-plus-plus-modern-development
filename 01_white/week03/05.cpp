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

    string GetFullNameWithHistory(int year) {
        string first_name = _get_names(_first_names, year);
        string last_name = _get_names(_last_names, year);

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

    static string _print_names(vector<string> names) {
        if (names.empty()) {
            return "";
        }

        if (names.size()==1) {
            return names[0];
        }

        string res = names[0] + " (";
        for (int i=1; i<names.size(); i++) {
            res += names[i];
            if (i!=names.size()-1) {
                res += ", ";
            }
        }
        res += ")";
        return res;
    }

    string _get_names(const map<int, string> &map, int year) {
        vector<string> names;

        string prev;
        for (auto iter = map.rbegin(); iter != map.rend(); ++iter) {
            if (iter->first > year) {
                continue;
            }

            if (iter->second != prev) {
                prev = iter->second;
                names.push_back(prev);
            }
        }

        return _print_names(names);
    }
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}
