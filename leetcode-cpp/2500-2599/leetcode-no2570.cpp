// problem: https://leetcode.cn/problems/merge-two-2d-arrays-by-summing-values/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> res;
        res.reserve(n + m);
        int i1 = 0, i2 = 0;
        while (i1 < n or i2 < m) {
            if (i1 < n and i2 < m) {
                const int id1 = nums1[i1][0], id2 = nums2[i2][0];
                if (id1 == id2)
                    res.emplace_back(vector{id1, nums1[i1++][1] + nums2[i2++][1]});
                else if (id1 < id2)
                    res.emplace_back(vector{id1, nums1[i1++][1]});
                else
                    res.emplace_back(vector{id2, nums2[i2++][1]});
            } else if (i1 < n) {
                res.emplace_back(nums1[i1++]);
            } else {
                res.emplace_back(nums2[i2++]);
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_matrix(test.mergeArrays(temp_vector({temp_vector({1, 2}), temp_vector({2, 3}), temp_vector({4, 5})}),
                                 temp_vector({temp_vector({1, 4}), temp_vector({3, 2}), temp_vector({4, 1})})));
}

//
// Created By jing At 2026-06-18 17:20
//
