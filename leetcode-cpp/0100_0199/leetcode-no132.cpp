#include <iostream>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;


class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool> > is_roll(n, vector<bool>(n, false));
        vector<int> dp(n,INT_MAX);

        for (int i = 0; i < n; i++) {
            is_roll[i][i] = true;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                if (i == 1) {
                    if (s[j] == s[j + 1]) {
                        is_roll[j][j + i] = true;
                    }
                } else {
                    if (is_roll[j + 1][j + i - 1] and s[j] == s[j + i]) {
                        is_roll[j][j + i] = true;
                    }
                }
            }
        }
        // show_matrix(is_roll);
        for (int i = 0; i < n; i++) {
            if (is_roll[0][i]) {
                dp[i] = 0;
            } else {
                for (int j = 0; j < i; ++j) {
                    if (is_roll[j + 1][i]) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }
        return dp[n - 1];
    }
};


class Solution2 {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<int> > dp(n, vector<int>(n,INT_MAX));

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                if (i == 1) {
                    if (s[j] == s[j + 1]) {
                        dp[j][j + i] = 1;
                    } else {
                        dp[j][j + i] = 2;
                    }
                } else {
                    if (dp[j + 1][j + i - 1] == 1 and s[j] == s[j + i]) {
                        dp[j][j + i] = 1;
                        continue;
                    }
                    for (int k = j; k < j + i; k++) {
                        dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i]);
                    }
                }
            }
        }
        return dp[0][n - 1] - 1;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minCut("ab") << endl;
    cout << test.minCut("a") << endl;
    cout << test.minCut("aab") << endl;
    cout << test.minCut("aaabccba") << endl;
}


//
// Created by ASUS on 2025/3/3.
//
