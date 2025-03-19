// problem: unique-3-digit-even-numbers
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution { // 没注意到是选三个，所以搞错了，之后用python暴力处理了。
public:
    int totalNumbers(vector<int> &digits) {
        unordered_map<int, int> cnts;
        int n = digits.size();
        int oc = 0;
        for (auto d: digits) {
            cnts[d]++;
            oc += d % 2;
        }
        auto factorial = [&](int n) -> long long {
            long long res = 1;
            for (int i = 2; i <= n; i++) {
                res *= i;
            }
            return res;
        };
        int dorm = 1;
        for (auto &[k,v]: cnts) {
            dorm *= factorial(v);
        }
        cout << factorial(n) << ", " << cnts[0] * factorial(n - 1) << ", " << oc * factorial(n - 1) << endl;
        return (factorial(n) - cnts[0] * factorial(n - 1) - oc * factorial(n - 1) + cnts[0] * factorial(n - 2) * oc) /
               dorm;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    vector<int> eg1 = {1, 2, 3, 4};
    cout << test.totalNumbers(eg1) << endl;
    vector<int> eg2 = {0, 2, 2};
    cout << test.totalNumbers(eg2) << endl;
    vector<int> eg3 = {6, 6, 6};
    cout << test.totalNumbers(eg3) << endl;
    vector<int> eg4 = {1, 6, 2, 8, 7};
    cout << test.totalNumbers(eg4) << endl;
}


//
// Created by ASUS on 2025/3/15.
//
