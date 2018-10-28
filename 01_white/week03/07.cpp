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
    Person(const string& first_name, const string& last_name, int year) {
        _first_names[year] = first_name;
        _last_names[year] = last_name;
    }


    void ChangeFirstName(int year, const string& first_name) {
        if (year < _first_names.begin()->first) {
            return;
        }
        _first_names[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        if (year < _last_names.begin()->first) {
            return;
        }
        _last_names[year] = last_name;
    }
    string GetFullName(int year) const {
        if (year < _last_names.begin()->first) {
            return "No person";
        }

        string first_name = _get_name(_first_names, year);
        string last_name = _get_name(_last_names, year);

        return _get_printable_names(first_name, last_name);
    }

    string GetFullNameWithHistory(int year) const {
        if (year < _last_names.begin()->first) {
            return "No person";
        }

        string first_name = _get_names(_first_names, year);
        string last_name = _get_names(_last_names, year);

        return _get_printable_names(first_name, last_name);
    }
private:
    map<int, string> _first_names;
    map<int, string> _last_names;

    static string _print_name(vector<string> names) {
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

    static string _get_names(const map<int, string> &map, int year) {
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

        return _print_name(names);
    }

    static string _get_name(const map<int, string> &map, int year) {
        for (auto iter = map.rbegin(); iter != map.rend(); ++iter) {
            if (iter->first > year) {
                continue;
            }

            return iter->second;
        }
        return "";
    }

    static string _get_printable_names(const string& first_name, const string& last_name) {
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
};

int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}
