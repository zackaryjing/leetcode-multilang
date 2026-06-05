// problem:
// https://leetcode.cn/problems/minimum-difference-between-highest-and-lowest-of-k-scores/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int minimumDifference(vector<int> &nums, int k) {
        ranges::sort(nums);
        int n = nums.size();
        int res = INT_MAX;
        for (int i = k - 1; i < n; ++i) {
            res = min(nums[i] - nums[i - k + 1], res);
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minimumDifference(temp_vector({90}), 1) << endl;
    cout << test.minimumDifference(temp_vector({9, 4, 1, 7}), 2) << endl;
}

//
// Created By jing At 2026-06-05 16:47
//
