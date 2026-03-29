// problem: https://leetcode.cn/problems/number-of-ways-to-split-a-string/?envType=problem-list-v2&envId=3rBpGyas
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int numWays(string s) {
        const unsigned long long n = s.size();
        int oneCnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                oneCnt++;
            }
        }
        if (oneCnt % 3 != 0) {
            return 0;
        }
        if (oneCnt == 0) {
            return static_cast<int>(((n - 1ULL) * (n - 2ULL) >> 1) % 1000000007);
        }
        const int firstCnt = oneCnt / 3, secondCnt = oneCnt / 3 * 2;
        int cnt = 0;
        int64_t firstZero = 0, secondZero = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                cnt++;
            } else if (cnt == firstCnt) {
                firstZero++;
            } else if (cnt == secondCnt) {
                secondZero++;
            }
        }
        return static_cast<int>((firstZero + 1ULL) * (secondZero + 1ULL) % 1000000007);
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.numWays("10101") << endl;
    cout << test.numWays("1001") << endl;
    cout << test.numWays("0000") << endl;
}

//
// Created By ASUS At 2026-02-10 23:14
//
