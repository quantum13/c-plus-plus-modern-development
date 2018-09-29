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

    map<string, vector<string>> bus_stops;
    map<string, vector<string>> stop_buses;

    string command_type;
    for(int i=0; i<size; i++) {
        cin >> command_type;

        if (command_type == "NEW_BUS") {
            string bus;
            int stop_count;
            cin >> bus >> stop_count;
            
            string stop_name;
            for (int j=0; j< stop_count; j++) {
                cin >> stop_name;
                bus_stops[bus].push_back(stop_name);
                stop_buses[stop_name].push_back(bus);
            }
        } else if (command_type == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;

            if (!stop_buses.count(stop)) {
                cout << "No stop" << endl;
            } else {
                for (const auto &b : stop_buses[stop]) {
                    cout << b << " ";
                }
                cout << endl;
            }
        } else if (command_type == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;

            if (!bus_stops.count(bus)) {
                cout << "No bus" << endl;
            } else {
                for (const auto &s : bus_stops[bus]) {
                    cout << "Stop " <<  s << ":";

                    if (stop_buses[s].size() == 1) {
                        cout << " no interchange";
                    }
                    for (const auto &b : stop_buses[s]) {
                        if (b != bus) {
                            cout << " "<< b;
                        }
                    }

                    cout << endl;
                }

            }
        } else if (command_type == "ALL_BUSES") {
            if (bus_stops.empty()) {
                cout << "No buses" << endl;
            } else {
                for (const auto &el : bus_stops) {
                    cout << "Bus " << el.first << ":" ;
                    for (const auto &s: el.second) {
                        cout << " "<< s;
                    }
                    cout << endl;
                }
            }

        }


    }

}
