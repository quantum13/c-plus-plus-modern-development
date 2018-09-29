#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>

using namespace std;


int main() {
    int size;


    cin >> size;

    map<string, set<string>> words;

    for(int i=0; i<size; i++) {
        string command;
        cin >> command;


        if (command == "ADD") {
            string a, b;
            cin >> a >> b;
            words[a].insert(b);
            words[b].insert(a);
        } else if (command == "COUNT") {
            string a;
            cin >> a;
            cout << words[a].size() << endl;
        } else if (command == "CHECK") {
            string a, b;
            cin >> a >> b;
            cout << (words[a].count(b) ? "YES" : "NO") << endl;
        }

    }

}
