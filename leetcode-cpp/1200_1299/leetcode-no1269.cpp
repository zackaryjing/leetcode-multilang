// problem: https://leetcode.cn/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/
#include <iostream>
#include <vector>

#include "../utils/vector_helper.h"
// time spent 1:53:26
using namespace std;

class Solution {
public:
    int numWays(int steps, int arrLen) {
        const int MODULO = 1000000007;
        const int fPos = min(steps / 2 + 1, arrLen);
        vector dp(fPos, 0);
        dp[0] = 1;
        for (int j = 0; j < steps; j++) {
            vector<int> nxt(fPos);
            // show_vector(dp);
            for (int i = 0; i < fPos; ++i) {
                nxt[i] = dp[i];
                if (i > 0) {
                    nxt[i] = (nxt[i] + dp[i - 1]) % MODULO;
                }
                if (i < fPos - 1) {
                    nxt[i] = (nxt[i] + dp[i + 1]) % MODULO;
                }
            }
            dp = nxt;
        }
        return dp[0];
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.numWays(3, 2) << endl;
    cout << test.numWays(4, 2) << endl;
    cout << test.numWays(2, 4) << endl;
}

//
// Created By Zackary At 2025-06-02 15:52:45
//
