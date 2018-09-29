#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


int main() {
    int size;

    vector< vector<string> > tasks_by_days(31);
    vector<int> days_in_monthes = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int current_month = 0;

    cin >> size;

    string command_type;
    for(int i=0; i<size; i++) {
        cin >> command_type;

        if (command_type == "ADD") {
            string task;
            int day;

            cin >> day >> task;

            tasks_by_days[day-1].push_back(task);
        } else if ( command_type == "NEXT") {
            int curr_days = days_in_monthes[current_month];
            current_month = (current_month + 1) % 12;
            int next_days = days_in_monthes[current_month];

            if (next_days < curr_days) {
                for (int j = next_days+1; j<= curr_days; j++) {
                    tasks_by_days[next_days-1].insert(
                        end(tasks_by_days[next_days-1]), begin(tasks_by_days[j-1]), end(tasks_by_days[j-1])
                    );
                }
            }

            tasks_by_days.resize(next_days);
        } else if ( command_type == "DUMP" ) {
            int day;
            cin >> day;

            cout << tasks_by_days[day-1].size();
            for (const auto &task : tasks_by_days[day-1]) {
                cout << " " << task;
            }
            cout << endl;
        }


    }

}

