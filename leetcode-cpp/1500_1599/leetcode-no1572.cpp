// problem: https://leetcode.cn/problems/matrix-diagonal-sum/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>> &mat) {
        int n = mat.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += mat[i][i];
            res += mat[i][n - i - 1];
        }
        if (n % 2 == 1) {
            res -= mat[n / 2][n / 2];
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.diagonalSum(temp_vector({temp_vector({1, 2, 3}), temp_vector({4, 5, 6}), temp_vector({7, 8, 9})}))
         << endl;
    cout << test.diagonalSum(temp_vector({temp_vector({1, 1, 1, 1}), temp_vector({1, 1, 1, 1}),
                                          temp_vector({1, 1, 1, 1}), temp_vector({1, 1, 1, 1})}))
         << endl;
}

//
// Created By ASUS At 2026-04-15 16:35
//
