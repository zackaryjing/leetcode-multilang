// problem:
// https://leetcode.cn/problems/the-k-weakest-rows-in-a-matrix/description/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<long long> keys(n);
        for (int i = 0; i < n; ++i) {
            long long cnt = 0;
            const auto &line = mat[i];
            for (int j = 0; j < m; ++j) {
                cnt += line[j];
            }
            keys[i] = (cnt << 32) + i;
        }
        // show_vector(keys);
        ranges::sort(keys);
        vector<int> res(k);
        for (int i = 0; i < k; ++i) {
            res[i] = static_cast<int>(keys[i]);
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.kWeakestRows(
    temp_vector({temp_vector({1, 1, 0, 0, 0}), temp_vector({1, 1, 1, 1, 0}), temp_vector({1, 0, 0, 0, 0}),
                 temp_vector({1, 1, 0, 0, 0}), temp_vector({1, 1, 1, 1, 1})}),
    3));
}

//
// Created By jing At 2026-05-16 22:38
//
