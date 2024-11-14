#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution2 {
public:
    pair<int, int> getCnt(string &nums) const {
        int oneCnt = 0, zeroCnt = 0;
        for (char num: nums) {
            if (num == '1') {
                oneCnt++;
            } else {
                zeroCnt++;
            }
        }
        return {zeroCnt, oneCnt};
    }

    int findMaxForm(vector<string> &strs, int m, int n) {
        int size = (int) strs.size();
        vector<vector<vector<int>>> dp = vector(size, vector(m + 1, vector(n + 1, 0)));
        {
            auto [zeroCnt, oneCnt] = getCnt(strs[0]);for (int i = 0; i <= m; ++i) { /* 0 */ for (int j = 0; j <= n; j++) { // 1
                    if (i >= zeroCnt and j >= oneCnt) {
                        dp[0][i][j] = 1;
                    } else {
                        dp[0][i][j] = 0;
                    }
                }
            }
        }
        for (int k = 1; k < size; k++) {
            auto [zeroCnt, oneCnt] = getCnt(strs[k]);
//            cout << zeroCnt << ", " << oneCnt << endl;
            for (int i = 0; i <= m; ++i) { // 0
                for (int j = 0; j <= n; j++) { // 1
                    if (i < zeroCnt or j < oneCnt) {
                        dp[k][i][j] = dp[k - 1][i][j];
                    } else {
                        dp[k][i][j] = max(dp[k - 1][i][j], 1 + dp[k - 1][i - zeroCnt][j - oneCnt]);
                    }
                }
            }

            for (auto k: dp[k]) {
                for (auto j: k) {
                    cout << j << " ";
                }
                cout << endl;
            }
            cout << string(40, '-') << endl;
        }
        return dp[size - 1][m][n];
    }
};


class Solution {
public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<int>> dp = vector(m + 1, vector(n + 1, 0));
        for (auto str: strs) {
            int zeroCnt = count(str.begin(), str.end(), '0'), oneCnt = str.size() - zeroCnt;
            for (int i = m; i >= zeroCnt; i--) { // 0
                for (int j = n; j >= oneCnt; j--) { // 1
                    if (i < zeroCnt or j < oneCnt) {
                        dp[i][j] = dp[i][j];
                    } else {
                        dp[i][j] = max(dp[i][j], 1 + dp[i - zeroCnt][j - oneCnt]);
                    }
                }
            }

/*
            for (auto k: dp) {
                for (auto j: k) {
                    cout << j << " ";
                }
                cout << endl;
            }
            cout << string(40, '-') << endl;
*/

        }
        return dp[m][n];
    }
};

int main() {
    Solution test;
    vector<string> test1 = {"10", "0001", "111001", "1", "0"};
    cout << test.findMaxForm(test1, 5, 3) << endl;
    vector<string> test2 = {"10", "0", "1"};
    cout << test.findMaxForm(test2, 1, 1) << endl;
}
//
// Created by ASUS on 2024/8/9.
//
