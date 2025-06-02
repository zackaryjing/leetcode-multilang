// problem: https://leetcode.cn/problems/count-number-of-texts/
#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000007

class Solution {
public:
    int countTexts(string pressedKeys) {
        vector<int64_t> threeSumData({0, 0, 1});
        auto threeSum = [&](int n)-> int64_t {
            n += 2;
            if (n >= threeSumData.size()) {
                for (int i = static_cast<int>(threeSumData.size()); i <= n; i++) {
                    threeSumData.push_back((threeSumData[i - 1] + threeSumData[i - 2] + threeSumData[i - 3]) % MOD);
                }
            }
            return threeSumData[n];
        };
        vector<int64_t> fourSumData({0, 0, 0, 1});
        auto fourSum = [&](int n)-> int64_t {
            n += 3;
            if (n >= fourSumData.size()) {
                for (int i = static_cast<int>(fourSumData.size()); i <= n; i++) {
                    fourSumData.push_back(
                            (fourSumData[i - 1] + fourSumData[i - 2] + fourSumData[i - 3] + fourSumData[i - 4]) % MOD);
                }
            }
            return fourSumData[n];
        };

        int cnt = 0;
        int64_t res = 1;
        char last = pressedKeys[0];
        for (const auto ch: pressedKeys) {
            if (ch != last) {
                if (last != '7' and last != '9') {
                    res *= threeSum(cnt);
                    res %= MOD;
                } else {
                    res *= fourSum(cnt);
                    res %= MOD;
                }
                cnt = 0;
                last = ch;
            }
            cnt++;
        }
        if (last != '7' and last != '9') {
            res *= threeSum(cnt);
            res %= MOD;
        } else {
            res *= fourSum(cnt);
            res %= MOD;
        }
        return static_cast<int>(res);
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.countTexts("22233") << endl;
    cout << test.countTexts("222222222222222222222222222222222222") << endl;
}

//
// Created By Zackary At 2025-05-30 17:59:40
//
