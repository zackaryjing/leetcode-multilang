#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static constexpr int INF = 0x3f3f3f3f;

    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        size_t n = floor.size();
        vector<vector<int> > dp(n + 1, vector<int>(numCarpets + 1, INF));
        for (int j = 0; j <= numCarpets; j++) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= n; i++) {
            dp[i][0] = (floor[i - 1] - '0') + dp[i - 1][0];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= numCarpets; ++j) {
                dp[i][j] = min(dp[i - 1][j] + (floor[i - 1] - '0'), dp[max(0, i - carpetLen)][j - 1]);
            }
        }
        return dp[n][numCarpets];
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minimumWhiteTiles("10110101", 2, 2) << endl;
}


//
// Created by ASUS on 2025/2/21.
//
