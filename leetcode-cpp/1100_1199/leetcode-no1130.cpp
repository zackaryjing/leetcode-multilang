// problem:
// https://leetcode.cn/problems/minimum-cost-tree-from-leaf-values/description/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int mctFromLeafValues(vector<int> &arr) {
        int n = arr.size();
        vector mx(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            int mxt = 0;
            for (int j = i; j < n; ++j) {
                mxt = max(mxt, arr[j]);
                mx[i][j] = mxt;
            }
        }
        vector dp(n, vector(n, 0));
        for (int length = 2; length <= n; ++length) {
            for (int left = 0; left <= n - length; ++left) {
                int right = left + length - 1;
                int temp = INT_MAX;
                for (int mid = left + 1; mid < left + length; ++mid) {
                    temp = min(temp, mx[left][mid - 1] * mx[mid][right] + dp[left][mid - 1] + dp[mid][right]);
                }
                dp[left][right] = temp;
            }
        }
        return dp[0][n - 1];
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.mctFromLeafValues(temp_vector({6, 2, 4})) << endl;
}

//
// Created By jing At 2026-05-11 23:09
//
