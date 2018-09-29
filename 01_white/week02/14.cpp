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

    set<string> words;

    for(int i=0; i<size; i++) {
        string word;
        cin >> word;
        words.insert(word);


    }

    cout << words.size();

}
