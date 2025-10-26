// problem: https://leetcode.cn/problems/minimum-increment-to-make-array-unique/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int> &nums) {
        ranges::sort(nums);
        int curMax = nums[0];
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= curMax) {
                res += curMax - nums[i];
                curMax++;
            } else {
                curMax = nums[i] + 1;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;

    cout << test.minIncrementForUnique(temp_vector({1, 2, 2})) << endl;
    cout << test.minIncrementForUnique(temp_vector({3, 2, 1, 2, 1, 7})) << endl;
}

//
// Created By jing At 2025-10-24 22:16
//
