#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


int main() {
    int size;
    cin >> size;

    vector<bool> queue;

    string command_type;
    int command_arg;
    for(int i=0; i<size; i++) {
        cin >> command_type;
        if (command_type != "WORRY_COUNT") {
            cin >> command_arg;
        }

        if (command_type == "WORRY") {
            queue[command_arg] = true;
        } else if(command_type == "QUIET") {
            queue[command_arg] = false;
        } else if(command_type == "COME") {
            queue.resize(queue.size() + command_arg, false);
        } else if(command_type == "WORRY_COUNT") {
            int cnt=0;
            for(auto el : queue) {
                if (el) cnt++;
            }
            cout << cnt << endl;
        }
    }

}

