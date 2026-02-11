// problem: https://leetcode.cn/problems/minimum-falling-path-sum/?envType=problem-list-v2&envId=OOhHf3Bc
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int> > &matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 1; i < n; ++i) {
            matrix[i][0] += min(matrix[i - 1][0], matrix[i - 1][1]);
            for (int j = 1; j < m - 1; ++j) {
                matrix[i][j] += min(matrix[i - 1][j], min(matrix[i - 1][j - 1], matrix[i - 1][j + 1]));
            }
            matrix[i][m - 1] += min(matrix[i - 1][m - 2], matrix[i - 1][m - 1]);
        }
        int res = INT_MAX;
        for (int j = 0; j < m; ++j) {
            res = min(res, matrix[n - 1][j]);
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minFallingPathSum(
        temp_vector({temp_vector({2, 1, 3}), temp_vector({6, 5, 4}), temp_vector({7, 8, 9})})) << endl;
}

//
// Created By ASUS At 2026-02-08 17:12
//
