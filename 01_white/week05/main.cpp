#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <vector>

using namespace std;

int RequireInt(istream&in, const string& error_string) {
    int res;
    if (!(in >> res)) {
        throw invalid_argument(error_string);
    }
    return res;
}

void EnsureNextHyphen(istream& in, const string& error_string) {
    char ch;
    if (!in.get(ch) || ch != '-') {
        throw invalid_argument(error_string);
    }
}
void EnsureEmpty(istream& in, const string& error_string) {
    char ch;
    if (in.get(ch)) {
        throw invalid_argument(error_string);
    }
}

class Date {
public:
    Date() = default;

    Date(int year, int month, int day) {
        Update(year, month, day);
    }

    int GetYear() const {
        return _year;
    }

    int GetMonth() const {
        return _month;
    }

    int GetDay() const {
        return _day;
    }

    void Update(int year, int month, int day) {
        if (month > 12 || month < 1) {
            throw range_error("Month value is invalid: " + to_string(month));
        }
        if (day < 1 || day > 31) {
            throw range_error("Day value is invalid: " + to_string(day));
        }
        _year = year;
        _month = month;
        _day = day;
    }

    bool operator<(const Date &rhs) const {
        if (_year == rhs.GetYear()) {
            if (_month == rhs.GetMonth()) {
                return _day < rhs.GetDay();
            } else {
                return _month < rhs.GetMonth();
            }
        } else {
            return _year < rhs.GetYear();
        }
    }


    friend istream &operator>>(istream &in, Date &r) {
        int year, month, day;
        string date;
        in >> date;
        stringstream date_stream(date);

        string error_string = "Wrong date format: " + date;

        year = RequireInt(date_stream, error_string);
        EnsureNextHyphen(date_stream, error_string);
        month = RequireInt(date_stream, error_string);
        EnsureNextHyphen(date_stream, error_string);
        day = RequireInt(date_stream, error_string);
        EnsureEmpty(date_stream, error_string);

        r.Update(year, month, day);

        return in;
    }

    friend ostream& operator<<(ostream& out, const Date& self) {
        out.fill('0');
        out.width(4);
        out << self._year << "-";
        out.width(2);
        out << self._month << "-";
        out.width(2);
        out << self._day;

        return out;
    }

private:
    int _year{0}, _month{0}, _day{0};
};


class Database {
public:
    void AddEvent(const Date &date, const string &event) {
        _data[date].insert(event);
    }

    bool DeleteEvent(const Date &date, const string &event) {
        return _data[date].erase(event) > 0;
    }

    int DeleteDate(const Date &date) {
        int count = _data[date].size();
        _data.erase(date);
        return count;
    }

    set<string> Find(const Date &date) const {
        set<string> empty;
        if (_data.count(date) == 0) {
            return empty;
        }
        return  _data.at(date);
    }

    void Print() const {
        for(auto const& events: _data) {
            for(auto const& event: events.second) {
                cout << events.first << " " << event << endl;
            }
        }
    }

private:
    map<Date, set<string>> _data;
};

int main() {
    Database db;

    string command_string;
    while (getline(cin, command_string)) {
        stringstream in(command_string);
        string command;

        in >> command;

        if (command == "Add") {
            Date date;
            string event;
            try {
                in >> date >> event;
            } catch (exception& e) {
                cout << e.what() << endl;
                return 0;
            }


            db.AddEvent(date, event);
        } else if (command == "Del") {
            Date date;
            string event;
            try {
                in >> date;
            } catch (exception& e) {
                cout << e.what() << endl;
                return 0;
            }

            if (in >> event) {
                bool res = db.DeleteEvent(date, event);
                if (res) {
                    cout << "Deleted successfully" << endl;
                } else {
                    cout << "Event not found" << endl;
                }
            } else {
                int res = db.DeleteDate(date);
                cout << "Deleted " << res << " events" << endl;
            }
        } else if (command == "Find") {
            Date date;
            try {
                in >> date;
            } catch (exception& e) {
                cout << e.what() << endl;
                return 0;
            }

            for (const string& el : db.Find(date)) {
                cout << el << endl;
            }

        } else if (command == "Print") {
            db.Print();
        } else {
            if (command.empty()) {
                continue;
            } else {
                cout << "Unknown command: " << command << endl;
                return 0;
            }

        }
    }

    return 0;
}