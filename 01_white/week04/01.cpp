#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>

using namespace std;

struct Specialization {
    string value;

    explicit Specialization(string val) {
        value = val;
    }
};

struct Course {
    string value;

    explicit Course(string val) {
        value = val;
    }
};

struct Week {
    string value;

    explicit Week(string val) {
        value = val;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle(Specialization new_spec, Course new_cource, Week new_week) {
        specialization = new_spec.value;
        course = new_cource.value;
        week = new_week.value;
    }
};

int main() {
    return 0;
};