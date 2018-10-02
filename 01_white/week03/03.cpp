#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>

using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        _strings.push_back(s);
        sort(begin(_strings), end(_strings));
    }
    vector<string> GetSortedStrings() {
        return _strings;
    }
private:
    vector<string> _strings;
};

//
//void PrintSortedStrings(SortedStrings& strings) {
//    for (const string& s : strings.GetSortedStrings()) {
//        cout << s << " ";
//    }
//    cout << endl;
//}
//
//int main() {
//    SortedStrings strings;
//
//    strings.AddString("first");
//    strings.AddString("third");
//    strings.AddString("second");
//    PrintSortedStrings(strings);
//
//    strings.AddString("second");
//    PrintSortedStrings(strings);
//
//    return 0;
//}