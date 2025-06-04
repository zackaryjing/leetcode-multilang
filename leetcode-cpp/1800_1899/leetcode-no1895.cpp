// problem: https://leetcode.cn/problems/largest-magic-square/
#include <iostream>
#include <vector>

#include "../utils/vector_helper.h"
using namespace std;


class Solution {
    // [Pass] Passed on first try, well, for this kind of problem, it's pretty rare.
public:
    int largestMagicSquare(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int edgeMax = min(n, m);
        vector horizontalSum(n, vector(m + 1, 0));
        vector verticalSum(n + 1, vector(m, 0));
        for (int i = 0; i < n; i++) {
            int tempLine = 0;
            for (int j = 1; j <= m; j++) {
                tempLine += grid[i][j - 1];
                horizontalSum[i][j] = tempLine;
            }
        }

        for (int j = 0; j < m; j++) {
            int tempLine = 0;
            for (int i = 1; i <= n; ++i) {
                tempLine += grid[i - 1][j];
                verticalSum[i][j] = tempLine;
            }
        }

        // cout << "origin: " << endl;
        // show_matrix(grid);
        // cout << "horizontalSum: " << endl;
        // show_matrix(horizontalSum);
        // cout << "verticalSum: " << endl;
        // show_matrix(verticalSum);
        // cout << "edgeMax: " << edgeMax << endl;

        for (int edge = edgeMax; edgeMax >= 1; edge--) {
            for (int i = 0; i + edge <= n; ++i) {
                for (int j = 0; j + edge <= m; ++j) {
                    // cout << "i: " << i << ", j: " << j << ", edge: " << edge << endl;
                    int val = horizontalSum[i][j + edge] - horizontalSum[i][j];
                    bool valid = true;
                    for (int k = i; k < i + edge; ++k) {
                        if (horizontalSum[k][j + edge] - horizontalSum[k][j] != val) {
                            valid = false;
                            break;
                        }
                    }
                    if (not valid) {
                        continue;
                    }
                    for (int k = j; k < j + edge; ++k) {
                        if (verticalSum[i + edge][k] - verticalSum[i][k] != val) {
                            valid = false;
                            break;
                        }
                    }
                    if (not valid) {
                        continue;
                    }
                    int ltToRb = 0;
                    int lbToRt = 0;
                    for (int k = 0; k < edge; ++k) {
                        ltToRb += grid[i + k][j + k];
                        lbToRt += grid[i + k][j + edge - k - 1];
                    }
                    if (ltToRb != val or lbToRt != val) {
                        valid = false;
                    }
                    if (valid) {
                        return edge;
                    }
                }
            }
        }
        return 1;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.largestMagicSquare(
            temp_vector({{7, 1, 4, 5, 6}, {2, 5, 1, 6, 4}, {1, 5, 4, 3, 2}, {1, 2, 7, 3, 4}})
            ) << endl;
    cout << test.largestMagicSquare(
            temp_vector({{5, 1, 3, 1}, {9, 3, 3, 1}, {1, 3, 3, 8}})
            ) << endl;
}

//
// Created By zhiya At 6/4/2025 2:10 PM
//
