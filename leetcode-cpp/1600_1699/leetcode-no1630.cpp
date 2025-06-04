// problem: https://leetcode.cn/problems/arithmetic-subarrays/
#include <iostream>
#include <vector>
// #include <algorithm>
#include <algorithm>

#include "../utils/vector_helper.h"

using namespace std;


class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r) {
        int n = (int) l.size();
        vector<bool> res;
        res.reserve(n);
        for (int i = 0; i < n; ++i) {
            int left = l[i];
            int right = r[i];
            if (right - left <= 1) {
                res.push_back(true);
                continue;
            }
            auto temp = vector(nums.begin() + left, nums.begin() + right + 1);
            ranges::sort(temp);
            // show_vector(nums);
            int d = temp[1] - temp[0];
            bool valid = true;
            for (int k = 1; k < right - left; k++) {
                if (temp[k + 1] - temp[k] != d) {
                    res.push_back(false);
                    valid = false;
                    break;
                }
            }
            if (valid) {
                res.push_back(true);
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.checkArithmeticSubarrays(temp_vector({4, 6, 5, 9, 3, 7}),
                                              temp_vector({0, 0, 2}),
                                              temp_vector({2, 3, 5})));

}

//
// Created By zhiya At 6/4/2025 2:18 PM
//