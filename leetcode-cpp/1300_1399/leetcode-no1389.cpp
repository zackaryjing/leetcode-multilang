// problem: https://leetcode.cn/problems/create-target-array-in-the-given-order/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <set>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    vector<int> createTargetArray(vector<int> &nums, vector<int> &index) {
        int n = nums.size();
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            int pos = index[i];
            if (res[pos] != 0) {
                for (int j = n - 1; j > pos; j--) {
                    res[j] = res[j - 1];
                }
            }
            res[pos] = nums[i] + 1;
        }
        for (int i = 0; i < n; ++i) res[i]--;
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.createTargetArray(temp_vector({0, 1, 2, 3, 4}), temp_vector({0, 1, 2, 2, 1})));
    show_vector(test.createTargetArray(temp_vector({0, 1, 2, 3, 4}), temp_vector({0, 0, 0, 0, 0})));
}

//
// Created By ASUS At 2026-03-18 13:14
//
