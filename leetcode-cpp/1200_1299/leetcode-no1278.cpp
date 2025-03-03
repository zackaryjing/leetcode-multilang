#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector cost(n, vector(n, 0));
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                if (s[j] != s[j + i]) {
                    cost[j][j + i] = cost[j + 1][j + i - 1] + 1;
                } else {
                    cost[j][j + i] = cost[j + 1][j + i - 1];
                }
            }
        }
        vector<vector<int> > dp(n + 1, vector<int>(k + 1,INT_MAX));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(k, i); ++j) {
                if (j == 1) {
                    dp[i][j] = cost[0][i - 1];
                } else {
                    for (int i0 = j - 1; i0 < i; ++i0) {
                        dp[i][j] = min(dp[i][j], dp[i0][j - 1] + cost[i0][i - 1]);
                    }
                }
            }
        }
        return dp[n][k];
    }
};

int main(int argc, char *argv[]) {
    Solution test;
}


//
// Created by ASUS on 2025/3/3.
//
