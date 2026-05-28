// problem: https://leetcode.cn/contest/biweekly-contest-183/problems/maximum-path-intersection-sum-in-a-grid/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int maxScore(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        const auto maxSub = [](const vector<int> &nums) -> int {
            int preSum = 0, mnPreSum1 = 0, mnPreSum2 = 1000000, mnPos = -1;
            int rs = -1000000;
            int s = nums.size();
            for (int i = 0; i < s; ++i) {
                preSum += nums[i];
                if (mnPos != i - 1) {
                    rs = max(rs, preSum - mnPreSum1);
                } else hhhhhhhhhhhhhhh{
                    rs = max(rs, preSum - mnPreSum2);
                }
                if (mnPreSum1 >= preSum) {
                    mnPos = i;
                    mnPreSum2 = mnPreSum1;
                    mnPreSum1 = preSum;
                } else if (mnPreSum2 > preSum) {
                    mnPreSum2 = preSum;
                }
            }
            return rs;
        };
        int res = -1000000;
        for (int i = 0; i < m; ++i) {
            res = max(maxSub(grid[i]), res);
        }
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                res = max(res, grid[i][j]);
            }
        }
        for (int j = 0; j < n; ++j) {
            vector<int> temp(m);
            for (int i = 0; i < m; ++i) {
                temp[i] = grid[i][j];
            }
            res = max(maxSub(temp), res);
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxScore(
                    temp_vector({temp_vector({1, 2, 0, -3}), temp_vector({1, -2, 1, 0}), temp_vector({-4, 2, -1, 3}),
                                 temp_vector({3, -3, 3, -2}), temp_vector({-1, -5, 0, 1})}))
         << endl;
    cout << test.maxScore(temp_vector({temp_vector({4, -2, -3}), temp_vector({-1, -3, -1}), temp_vector({-4, 2, -1})}))
         << endl;
    cout << test.maxScore(temp_vector({temp_vector({-15, -16}), temp_vector({-7, 12})})) << endl;
}

//
// Created By jing At 2026-05-23 23:00
//
