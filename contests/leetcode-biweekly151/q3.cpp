#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int minCost(vector<int> &nums) {
        int n = nums.size();
        vector dp(n + 1, vector<int>(n));
        dp[n] = nums;
        for (int i = 0; i < n; i++) {
            dp[n - 1][i] = max(nums[i], nums[n - 1]);
        }
        for (int i = n - 3 + n % 2; i > 0; i -= 2) {
            int b = nums[i], c = nums[i + 1];
            for (int j = 0; j < i; j++) {
                int a = nums[j];
                dp[i][j] = min({
                    dp[i + 2][j] + max(b, c),
                    dp[i + 2][i] + max(a, c),
                    dp[i + 2][i + 1] + max(a, b)
                });
            }
        }
        return dp[1][0];
    }
};


int main(int argc, char *argv[]) {
    Solution test;
}


//
// Created by ASUS on 2025/3/1.
//
