// problem: https://leetcode.cn/problems/maximum-non-negative-product-in-a-matrix/
#include <iostream>
#include <vector>
#include "../utils/vector_helper.h"
using namespace std;

// time spent: 43:52

class Solution {
public:
    int maxProductPath(vector<vector<int>> &grid) {
        int n = static_cast<int>(grid.size());
        int m = static_cast<int>(grid[0].size());
        constexpr int modulo = 1000000007;
        vector posMax(n, vector<long long>(m));
        vector negMax(n, vector<long long>(m));
        posMax[0][0] = max(grid[0][0], 0);
        negMax[0][0] = min(grid[0][0], 0);
        bool hasOne = grid[0][0] == 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int cur = grid[i][j];
                if (i - 1 >= 0) {
                    if (cur > 0) {
                        posMax[i][j] = posMax[i - 1][j] * cur;
                        negMax[i][j] = negMax[i - 1][j] * cur;
                    } else if (cur < 0) {
                        posMax[i][j] = negMax[i - 1][j] * cur;
                        negMax[i][j] = posMax[i - 1][j] * cur;
                    } else {
                        hasOne = true;
                        posMax[i][j] = 0;
                        negMax[i][j] = 0;
                    }
                }
                if (j - 1 >= 0) {
                    if (cur > 0) {
                        posMax[i][j] = max(posMax[i][j], posMax[i][j - 1] * cur);
                        negMax[i][j] = min(negMax[i][j], negMax[i][j - 1] * cur);
                    } else if (cur < 0) {
                        posMax[i][j] = max(posMax[i][j], negMax[i][j - 1] * cur);
                        negMax[i][j] = min(negMax[i][j], posMax[i][j - 1] * cur);
                    } else {
                        hasOne = true;
                        posMax[i][j] = 0;
                        negMax[i][j] = 0;
                    }
                }
            }
        }
        return posMax[n - 1][m - 1] > 0 ? static_cast<int>(posMax[n - 1][m - 1] % modulo) : hasOne ? 0 : -1;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxProductPath(temp_vector({temp_vector({2, 1, 3, 0, -3, 3, -4, 4, 0, -4}),
                                             temp_vector({-4, -3, 2, 2, 3, -3, 1, -1, 1, -2}),
                                             temp_vector({-2, 0, -4, 2, 4, -3, -4, -1, 3, 4}),
                                             temp_vector({-1, 0, 1, 0, -3, 3, -2, -3, 1, 0}),
                                             temp_vector({0, -1, -2, 0, -3, -4, 0, 3, -2, -2}),
                                             temp_vector({-4, -2, 0, -1, 0, -3, 0, 4, 0, -3}),
                                             temp_vector({-3, -4, 2, 1, 0, -4, 2, -4, -1, -3}),
                                             temp_vector({3, -2, 0, -4, 1, 0, 1, -3, -1, -1}),
                                             temp_vector({3, -4, 0, 2, 0, -2, 2, -4, -2, 4}),
                                             temp_vector({0, 4, 0, -3, -4, 3, 3, -1, -2, -2})})) << endl;
    cout << test.maxProductPath(temp_vector({temp_vector({1, 4, 4, 0}), temp_vector({-2, 0, 0, 1}),
                                             temp_vector({1, -1, 1, 1})})) << endl;
    cout << test.maxProductPath(temp_vector({temp_vector({-1, -2, -3}), temp_vector({-2, -3, -3}),
                                             temp_vector({-3, -3, -2})})) << endl;
    cout << test.maxProductPath(temp_vector({temp_vector({1, 3}), temp_vector({0, -4})})) << endl;
    cout << test.maxProductPath(
            temp_vector({temp_vector({1, -2, 1}), temp_vector({1, -2, 1}), temp_vector({3, -4, 1})})) << endl;
}

//
// Created By Zackary At 2025-06-09 18:38:23
//
