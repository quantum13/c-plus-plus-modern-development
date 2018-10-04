#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>

using namespace std;

//struct Image {
//    double quality;
//    double freshness;
//    double rating;
//};
//
//struct Params {
//    double a;
//    double b;
//    double c;
//};

class FunctionPart {
public:
    FunctionPart(char op, double value) {
        _op = op;
        _value = value;
    }

    void Invert() {
        _op = _reversed_ops[_op];
    }

    double Apply(double val) const {
        switch (_op) {
            case '-':
                return val - _value;
            case '+':
                return val + _value;
            case '*':
                return val * _value;
            case '/':
                return val / _value;
        }
    }

private:
    char _op;
    double _value;
    map<char, char> _reversed_ops = {
        {'-', '+'}, {'+', '-'}, {'*', '/'}, {'/', '*'}
    };
};

class Function {

public:
    void AddPart(char op, double val) {
        _parts.push_back({op, val});
    }

    double Apply(double val) const {
        for (auto& part : _parts) {
            val = part.Apply(val);
        }
        return val;
    }

    void Invert() {
        for (auto& part : _parts) {
            part.Invert();
        }
        reverse(begin(_parts), end(_parts));
    }

private:
    vector<FunctionPart> _parts;
};

//Function MakeWeightFunction(const Params& params,
//                            const Image& image) {
//    Function function;
//    function.AddPart('*', params.a);
//    function.AddPart('-', image.freshness * params.b);
//    function.AddPart('+', image.rating * params.c);
//    return function;
//}
//
//double ComputeImageWeight(const Params& params, const Image& image) {
//    Function function = MakeWeightFunction(params, image);
//    return function.Apply(image.quality);
//}
//
//double ComputeQualityByWeight(const Params& params,
//                              const Image& image,
//                              double weight) {
//    Function function = MakeWeightFunction(params, image);
//    function.Invert();
//    return function.Apply(weight);
//}
//
//int main() {
//    Image image = {10, 2, 6};
//    Params params = {4, 2, 6};
//    cout << ComputeImageWeight(params, image) << endl;
//    cout << ComputeQualityByWeight(params, image, 52) << endl;
//    return 0;
//}
