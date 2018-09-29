#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;


int main() {
    int size;


    cin >> size;

    map<string, string> capitals;

    string command_type;
    for(int i=0; i<size; i++) {
        cin >> command_type;

        if (command_type == "CHANGE_CAPITAL") {
            string country, new_capital;
            cin >> country >> new_capital;

            if (capitals.count(country) == 0 ) {
                cout << "Introduce new country " << country << " with capital " << new_capital << endl;
            } else {
                if (capitals[country] == new_capital) {
                    cout << "Country " << country << " hasn't changed its capital" << endl;
                } else {
                    cout << "Country " << country << " has changed its capital from " << capitals[country] << " to " << new_capital << endl;
                }
            }

            capitals[country] = new_capital;

        } else if (command_type == "RENAME") {
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;

            if (
                    old_country_name == new_country_name
                    || capitals.count(old_country_name) == 0
                    || capitals.count(new_country_name) != 0
            ) {
                cout << "Incorrect rename, skip" << endl;
                continue;
            } else {
                cout << "Country " << old_country_name << " with capital " << capitals[old_country_name] << " has been renamed to " << new_country_name << endl;
            }

            capitals[new_country_name] = capitals[old_country_name];
            capitals.erase(old_country_name);

        } else if (command_type == "ABOUT") {
            string country;
            cin >> country;

            if (capitals.count(country) == 0) {
                cout << "Country " << country << " doesn't exist" << endl;
            } else {
                cout << "Country " << country << " has capital " << capitals[country] << endl;
            }

        } else if (command_type == "DUMP") {
            if (capitals.empty()) {
                cout << "There are no countries in the world" << endl;
            } else {
                for (const auto &el : capitals) {
                    cout << el.first << "/" << el.second << " ";
                }
                cout << endl;
            }
        }


    }

}

