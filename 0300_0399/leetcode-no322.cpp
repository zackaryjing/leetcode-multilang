#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        if (amount == 0) return 0;
        int m = coins.size();
        vector<int> dp(1 + amount, 0);
        for (int i = 0; i < m; ++i) {
            if (coins[i] <= amount) {
                dp[coins[i]] = 1;
            }
        }
        for (int i = 1; i < 1 + amount; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i > coins[j]) {
                    dp[i] = dp[i] != 0 ?
                            min(dp[i], dp[i - coins[j]] != 0 ? dp[i - coins[j]] + 1 : dp[i]) :
                            dp[i - coins[j]] != 0 ? dp[i - coins[j]] + 1 : dp[i];
                }
            }
        }
        return dp[amount] ? dp[amount] : -1;
    }
};


int main() {
    Solution test;
    vector<int> coins1 = {1, 2, 5};
    cout << test.coinChange(coins1, 11) << endl;
    cout << endl;
    vector<int> coins2 = {2};
    cout << test.coinChange(coins2, 3) << endl;
    cout << endl;
    vector<int> coins3 = {1};
    cout << test.coinChange(coins3, 1) << endl;
    vector<int> coins4 = {2};
    cout << test.coinChange(coins4, 1) << endl;
}
//
// Created by ASUS on 2024/3/16.
//
