// problem:
// https://leetcode.cn/problems/maximum-sum-of-two-non-overlapping-subarrays/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int maxRes(vector<int> &nums, int firstLen, int secondLen) {
        int n = nums.size();
        int left = std::accumulate(nums.begin(), nums.begin() + firstLen, 0);
        int right = std::accumulate(nums.begin() + firstLen, nums.begin() + firstLen + secondLen, 0);
        int maxLeft = left;
        int res = left + right;
        for (int i = firstLen + secondLen; i < n; ++i) {
            right = right + nums[i] - nums[i - secondLen];
            left = left + nums[i - secondLen] - nums[i - secondLen - firstLen];
            maxLeft = max(left, maxLeft);
            res = max(maxLeft + right, res);
        }
        return res;
    }
    int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {
        return max(maxRes(nums, firstLen, secondLen), maxRes(nums, secondLen, firstLen));
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxSumTwoNoOverlap(temp_vector({0, 6, 5, 2, 2, 5, 1, 9, 4}), 1, 2) << endl;
    cout << test.maxSumTwoNoOverlap(temp_vector({3, 8, 1, 3, 2, 1, 8, 9, 0}), 3, 2) << endl;
    cout << test.maxSumTwoNoOverlap(temp_vector({2, 1, 5, 6, 0, 9, 5, 0, 3, 8}), 4, 3) << endl;
}

//
// Created By jing At 2026-05-03 21:55
//
