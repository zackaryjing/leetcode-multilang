// problem:
// https://leetcode.cn/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <cmath>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    int maxSideLength(vector<vector<int>> &mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        vector ex_mat(n + 1, vector(m + 1, 0));
        for (int i = 1; i <= n; ++i) {
            int lineSum = 0;
            for (int j = 1; j <= m; ++j) {
                lineSum += mat[i - 1][j - 1];
                ex_mat[i][j] = lineSum + ex_mat[i - 1][j];
            }
        }
        // show_matrix(ex_mat);
        for (int width = min(m, n); width >= 1; --width) {
            for (int i = 0; i <= n - width; ++i) {
                const auto &line1 = ex_mat[i];
                const auto &line2 = ex_mat[i + width];
                for (int j = 0; j <= m - width; ++j) {
                    if (line2[j + width] + line1[j] - line2[j] - line1[j + width] <= threshold) {
                        return width;
                    }
                }
            }
        }
        return 0;
    }
};

class Solution {
public:
    int maxSideLength(vector<vector<int>> &mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        vector ex_mat(n + 1, vector(m + 1, 0));
        for (int i = 1; i <= n; ++i) {
            int lineSum = 0;
            for (int j = 1; j <= m; ++j) {
                lineSum += mat[i - 1][j - 1];
                ex_mat[i][j] = lineSum + ex_mat[i - 1][j];
            }
        }
        int left = 0, right = min(m, n);
        while (left < right) {
            int mid = (left + right + 1) / 2;
            int width = mid;
            for (int i = 0; i <= n - width; ++i) {
                const auto &line1 = ex_mat[i];
                const auto &line2 = ex_mat[i + width];
                for (int j = 0; j <= m - width; ++j) {
                    if (line2[j + width] + line1[j] - line2[j] - line1[j + width] <= threshold) {
                        left = mid;
                        goto nxt;
                    }
                }
            }
            right = mid - 1; // only not found gets here
            nxt: ;
        }
        return left;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxSideLength(
            temp_vector({temp_vector({2, 2, 2, 2, 2}), temp_vector({2, 2, 2, 2, 2}), temp_vector({2, 2, 2, 2, 2}),
                         temp_vector({2, 2, 2, 2, 2}), temp_vector({2, 2, 2, 2, 2})}),
            1)
         << endl;
    cout << test.maxSideLength(temp_vector({temp_vector({1, 1, 3, 2, 4, 3, 2}), temp_vector({1, 1, 3, 2, 4, 3, 2}),
                                            temp_vector({1, 1, 3, 2, 4, 3, 2})}),
                               4)
         << endl;
    cout << test.maxSideLength(temp_vector({temp_vector({10, 10, 10, 10, 10, 10}), temp_vector({10, 10, 10, 10, 1, 1}),
                                            temp_vector({10, 10, 10, 10, 1, 1})}),
                               4)
         << endl;
}

//
// Created By jing At 2026-11-13 15:02
//
