#include <functional>
#include <iostream>
#include <vector>

#include "../../utils/vector_helper.h"

using namespace std;


class Solution {
public:
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        vector f(k + 1, vector(n, vector<int>(n)));
        for (int g = 0; g <= k; g++) {
            for (int i = n - 1; i >= 0; i--) {
                f[g][i][i] = 1;
                for (int j = i + 1; j < n; j++) {
                    int res = max(f[g][i + 1][j], f[g][i][j - 1]);
                    int d = abs(s[i] - s[j]);
                    int op = min(d, 26 - d);
                    if (op <= g) {
                        res = max(res, f[g - op][i + 1][j - 1] + 2);
                    }
                    f[g][i][j] = res;
                }
            }
        }
        return f[k][0][n - 1];
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.longestPalindromicSubsequence("aaazzz", 4) << endl;
    cout << test.longestPalindromicSubsequence("abced", 2) << endl;
}

class Solution2 {
    // 我是废柴，结束之后14分钟才写出来，结果还超时，郁郁了
    // dp 一点不会
public:
    vector<vector<int> > cost;
    int n;
    int ans = INT_MIN;
    int k;

    unordered_map<int, int> sc; // size & cost
    void dfs(int x, int y, int c, int size) {
        // cout << x << " , " << y << " , " << c << " , " << size << endl;
        if (c <= k) {
            ans = max(size, ans);
            for (int i = x + 1; i < n; i++) {
                for (int j = y - 1; j >= i; j--) {
                    if (i == j) {
                        ans = max(size + 1, ans);
                    } else {
                        dfs(i, j, c + cost[i][j], size + 2);
                    }
                }
            }
        }
    }

    int longestPalindromicSubsequence(string s, int k) {
        n = s.size();
        this->k = k;
        cost = vector(n, vector<int>(n, 0));

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                cost[j][j + i] = min((s[j] - s[j + i] + 26) % 26, (s[j + i] - s[j] + 26) % 26);
            }
        }

        // for (auto k: cost) {
        //     show_vector(k);
        // }

        dfs(-1, n, 0, 0);
        return ans;
    }
};


//
// Created by ASUS on 2025/3/2.
//
