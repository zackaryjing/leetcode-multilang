// problem:  https://leetcode.cn/problems/largest-submatrix-with-rearrangements/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>> &matrix) {
        const int n = matrix.size(), m = matrix[0].size();
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < m; ++j) {
                matrix[i][j] = matrix[i][j] ? matrix[i + 1][j] + 1 : 0;
            }
        }
        int res = 0;
        for (auto &line : matrix) {
            ranges::sort(line, [&](const auto &a, const auto &b) { return a > b; });
            int mnOnes = line[0], tempRes = mnOnes;
            for (int j = 1; j < m; ++j) {
                mnOnes = min(mnOnes, line[j]);
                tempRes = max(tempRes, (j + 1) * mnOnes);
            }
            res = max(res, tempRes);
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.largestSubmatrix(temp_vector({temp_vector({0, 0, 1}), temp_vector({1, 1, 1}), temp_vector({1, 0, 1})}))
         << endl;
    cout << test.largestSubmatrix(temp_vector({temp_vector({1, 0, 1, 0, 1})})) << endl;
    cout << test.largestSubmatrix(temp_vector({temp_vector({1, 1, 0}), temp_vector({1, 0, 1})})) << endl;
}

//
// Created By jing At 2026-06-04 17:48
//
