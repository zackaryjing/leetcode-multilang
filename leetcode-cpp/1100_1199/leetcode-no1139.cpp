// problem: https://leetcode.cn/problems/largest-1-bordered-square/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size(), res = grid[0][0];
        vector col(n, vector<int>(m)), row(n, vector<int>(m));
        col[0][0] = grid[0][0], row[0][0] = grid[0][0];
        for (int i = 1; i < max(n, m); ++i) {
            if (i < m and grid[0][i]) res = 1, col[0][i] = 1, row[0][i] = row[0][i - 1] + 1;
            if (i < n and grid[i][0]) res = 1, row[i][0] = 1, col[i][0] = col[i - 1][0] + 1;
        }
        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                if (grid[i][j]) res = 1, row[i][j] = row[i][j - 1] + 1, col[i][j] = col[i - 1][j] + 1;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j])
                    for (int k = min(n - i, m - j); k >= 2; k--) {
                        int a1, a2, b1, b2;
                        if (i > 0)
                            a1 = col[i + k - 1][j] - col[i - 1][j],
                            a2 = col[i + k - 1][j + k - 1] - col[i - 1][j + k - 1];
                        else
                            a1 = col[i + k - 1][j], a2 = col[i + k - 1][j + k - 1];
                        if (a1 != k or a2 != k) continue;
                        if (j > 0)
                            b1 = row[i][j + k - 1] - row[i][j - 1],
                            b2 = row[i + k - 1][j + k - 1] - row[i + k - 1][j - 1];
                        else
                            b1 = row[i][j + k - 1], b2 = row[i + k - 1][j + k - 1];
                        if (b1 != k or b2 != k) continue;
                        res = max(res, k * k);
                        break;
                    }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.largest1BorderedSquare(
            temp_vector({temp_vector({1, 1, 1}), temp_vector({1, 0, 1}), temp_vector({1, 1, 1})}))
         << endl;
    cout << test.largest1BorderedSquare(temp_vector({temp_vector({1, 1, 0, 0})})) << endl;
    cout << test.largest1BorderedSquare(temp_vector({temp_vector({0, 1}), temp_vector({1, 1})})) << endl;
}

//
// Created By jing At 2026-05-12 00:53
//
