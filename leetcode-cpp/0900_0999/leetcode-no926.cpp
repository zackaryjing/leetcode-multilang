// problem: https://leetcode.cn/problems/flip-string-to-monotone-increasing/description/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int tempZeroCnt = 0;
        vector<int> zeroCnt(n);
        for (int i = n - 1; i >= 0; --i) {
            zeroCnt[i] = tempZeroCnt;
            tempZeroCnt += s[i] == '0';
        }

        int res = tempZeroCnt;
        int tempOneCnt = 0;
        for (int i = 0; i < n; ++i) {
            tempOneCnt += s[i] == '1';
            res = min(res, tempOneCnt + zeroCnt[i]);
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minFlipsMonoIncr("0010") << endl;
    cout << test.minFlipsMonoIncr("11011") << endl;
    cout << test.minFlipsMonoIncr("010110") << endl;
    cout << test.minFlipsMonoIncr("00011000") << endl;
    cout << test.minFlipsMonoIncr("100111111100101110110") << endl;
    cout << test.minFlipsMonoIncr("00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000000000000000000000") << endl;
}

//
// Created By Zackary At 2025-06-03 21:34:58
//
