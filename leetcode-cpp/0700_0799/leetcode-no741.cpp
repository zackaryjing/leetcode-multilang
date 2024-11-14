#include <iostream>
#include <vector>

using namespace std;

class Solution2 {
public:
    int cherryPickup(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == -1) {
                    dp[i][j] = 0;
                } else {
                    if (i > 0 and j > 0) {
                        if (grid[i - 1][j] == -1 and grid[i][j - 1] == -1) {
                            dp[i][j] = 0;
                            continue;
                        }
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + grid[i][j];
                    } else if (i > 0) {
                        if (grid[i - 1][j] == -1) {
                            dp[i][j] = 0;
                            continue;
                        }
                        dp[i][j] = dp[i - 1][j] + grid[i][j];
                    } else if (j > 0) {
                        if (grid[i][j - 1] == -1) {
                            dp[i][j] = 0;
                        }
                        dp[i][j] = dp[i][j - 1] + grid[i][j];
                    } else {
                        dp[i][j] = grid[i][j];
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[n - 1][m - 1];
    }
};

class Solution {
public:
    int cherryPickup(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(2 * n - 1, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        dp[0][0][0] = grid[0][0];
        for (int k = 1; k < 2 * n - 1; k++) {
            for (int x1 = max(k - n + 1, 0); x1 < min(k + 1, n); x1++) {
                int y1 = k - x1;
                if (grid[x1][y1] == -1) {
                    continue;
                }
                for (int x2 = x1; x2 < min(k + 1, n); x2++) {
                    int y2 = k - x2;
//                    cout << k << " " << x1 << " " << x2 << endl;
                    if (grid[x2][y2] == -1) {
                        continue;
                    }
                    int res = dp[k - 1][x1][x2];
                    if (x1) {
                        res = max(res, dp[k - 1][x1 - 1][x2]);
                    }
                    if (x2) {
                        res = max(res, dp[k - 1][x1][x2 - 1]);
                    }
                    if (x1 and x2) {
                        res = max(res, dp[k - 1][x1 - 1][x2 - 1]);
                    }
                    res += grid[x1][y1];
                    if (x1 != x2) {
                        res += grid[x2][y2];
                    }
                    dp[k][x1][x2] = res;
                }
            }
        }
        return max(dp[2 * n - 2][n - 1][n - 1],0);
    }
};


int main() {
    Solution test;

    vector<vector<int>> cherry1 = {{0, 1, -1},
                                   {1, 0, -1},
                                   {1, 1, 1}};
    cout << test.cherryPickup(cherry1) << endl;
    vector<vector<int>> cherry2 = {{0, 1, -1},
                                   {1, 0, -1},
                                   {1, 1, 1}};
    cout << test.cherryPickup(cherry2) << endl;
}

