// problem: https://leetcode.cn/problems/find-kth-largest-xor-coordinate-value/?envType=problem-list-v2&envId=OOhHf3Bc
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int> > &matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> exclusiveOr;
        exclusiveOr.reserve(n * m);
        exclusiveOr.push_back(matrix[0][0]);
        for (int j = 1; j < m; ++j) {
            matrix[0][j] = matrix[0][j] ^ matrix[0][j - 1];
            exclusiveOr.push_back(matrix[0][j]);
        }
        for (int i = 1; i < n; ++i) {
            matrix[i][0] = matrix[i][0] ^ matrix[i - 1][0];
            exclusiveOr.push_back(matrix[i][0]);
            for (int j = 1; j < m; ++j) {
                matrix[i][j] ^= matrix[i][j - 1] ^ (matrix[i - 1][j - 1] ^ matrix[i - 1][j]);
                exclusiveOr.push_back(matrix[i][j]);
            }
        }
        ranges::nth_element(exclusiveOr, exclusiveOr.begin() + n * m - k);
        return *(exclusiveOr.begin() + n * m - k);
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.kthLargestValue(temp_vector({{5, 2}, {1, 6}}), 1) << endl;
    cout << test.kthLargestValue(temp_vector({{5, 2}, {1, 6}}), 2) << endl;
    cout << test.kthLargestValue(temp_vector({{5, 2}, {1, 6}}), 3) << endl;
}

//
// Created By ASUS At 2026-02-06 22:54
//
