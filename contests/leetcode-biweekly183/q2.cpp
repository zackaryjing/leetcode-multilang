// problem:
// https://leetcode.cn/contest/biweekly-contest-183/problems/minimum-operations-to-make-array-modulo-alternating-i/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums, int k) {
        for (auto &num: nums) {
            num %= k;
        }
        // show_vector(nums);
        int n = nums.size();
        int mnx1 = INT_MAX, mnx2 = INT_MAX, px1 = 0;
        for (int i = 0; i < k; ++i) {
            int val = 0;
            for (int j = 0; j < n; j += 2) {
                val += min(min(abs(nums[j] - i), abs(nums[j] - (i + k))), nums[j] + k - i);
            }
            if (val <= mnx1) {
                mnx2 = mnx1;
                mnx1 = val;
                px1 = i;
            } else if (val <= mnx2) {
                mnx2 = val;
            }
        }
        int mny1 = INT_MAX, mny2 = INT_MAX, py1 = 0;
        for (int i = 0; i < k; ++i) {
            int val = 0;
            for (int j = 1; j < n; j += 2) {
                val += min(min(abs(nums[j] - i), abs(nums[j] - (i + k))), nums[j] + k - i);
            }
            if (val <= mny1) {
                mny2 = mny1;
                mny1 = val;
                py1 = i;
            } else if (val <= mny2) {
                mny2 = val;
            }
        }
        if (px1 == py1) {
            return min(mnx1 + mny2, mnx2 + mny1);
        }
        return mnx1 + mny1;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minOperations(temp_vector({1, 4, 2, 8}), 3) << endl;
    cout << test.minOperations(temp_vector({1, 1, 1}), 3) << endl;
    cout << test.minOperations(temp_vector({73, 92, 31, 78, 89}), 17) << endl;
}

//
// Created By jing At 2026-05-23 22:33
//
