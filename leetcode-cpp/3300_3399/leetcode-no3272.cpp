// problem:  BEGIN
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        std::pmr::unordered_set<string> dict;
        int base = pow(10, (n + 1) / 2);
        int skip = n % 2;
        for (int i = base / 10; i < base; ++i) {
            string num = to_string(i);
            num += string(num.rbegin() + skip, num.rend());
            long long val = stoll(num);
            if (val % k == 0) {
                std::ranges::sort(num);
                dict.insert(num);
            }
        }
        vector<int> factorial(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }
        long long res = 0;
        for (const auto &s: dict) {
            vector<int> times(10, 0);
            for (const char i: s) {
                times[i - '0']++;
            }
            int temp = (n - times[0]) * factorial[n - 1];
            for (auto time: times) {
                temp /= factorial[time];
            }
            res += temp;
        }
        return res;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.countGoodIntegers(9, 5) << endl;
    cout << test.countGoodIntegers(3, 5) << endl;
    cout << test.countGoodIntegers(1, 4) << endl;
    cout << test.countGoodIntegers(5, 6) << endl;
}


//
// Created by ASUS on 2025/4/12.
//
