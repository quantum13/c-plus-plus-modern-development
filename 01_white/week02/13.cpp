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

    map<vector<string>, int> buses;

    for(int i=0; i<size; i++) {
        vector<string> stops;
        int count;
        cin >> count;
        for (int j=0; j< count; j++) {
            string stop;
            cin >> stop;
            stops.push_back(stop);
        }

        if (buses.count(stops)) {
            cout << "Already exists for " << buses[stops] << endl;
        } else {
            int num = buses.size() +1;
            buses[stops] = num;
            cout << "New bus " << num << endl;
        }


    }

}
