#include <iostream>
#include <memory>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    int maximumSum(vector<int> &arr) {
        int n = arr.size();
        vector<int> dp[2] = {vector<int>(n,INT_MIN), vector<int>(n,INT_MIN)};
        dp[0][0] = arr[0];
        dp[1][0] = arr[0];
        int ans = INT_MIN;
        for (int i = 1; i < n; i++) {
            dp[0][i] = max(arr[i], dp[0][i - 1] + arr[i]);
            dp[1][i] = max(dp[1][i - 1] + arr[i], dp[0][i - 1]);
            ans = max({ans, dp[0][i], dp[1][i]});
        }
        return max({ans, dp[0][0], dp[1][0]});
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maximumSum(*make_unique<vector<int> >(vector{-50})) << endl;
    cout << test.maximumSum(*make_unique<vector<int> >(vector{1, -2, 0, 3})) << endl;
    cout << test.maximumSum(*make_unique<vector<int> >(vector{1, -2, -2, 3})) << endl;
    cout << test.maximumSum(*make_unique<vector<int> >(vector{-1, -1, -1, -1})) << endl;
}


//
// Created by ASUS on 2025/3/3.
//
