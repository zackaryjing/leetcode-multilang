// problem: https://leetcode.cn/problems/decrease-elements-to-make-array-zigzag/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int movesToMakeZigzag(vector<int> &nums) {
        const int n = nums.size();
        if (n == 1) return 0;
        int r1 = max(0, nums[0] - nums[1] + 1) + (n & 1 ? max(0, nums[n - 1] - nums[n - 2] + 1) : 0),
            r2 = not(n & 1) ? max(0, nums[n - 1] - nums[n - 2] + 1) : 0;
        for (int i = 1; i < n - 1; ++i) (i & 1 ? r2 : r1) += max(0, nums[i] - min(nums[i - 1] - 1, nums[i + 1] - 1));
        return min(r2, r1);
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.movesToMakeZigzag(temp_vector({1, 2, 3})) << endl;
    cout << test.movesToMakeZigzag(temp_vector({9, 6, 1, 6, 2})) << endl;
    cout << test.movesToMakeZigzag(temp_vector({151, 42,  769, 349, 835, 92,  242, 82,  357, 494, 880, 683, 470, 631,
                                                479, 298, 941, 113, 892, 103, 755, 575, 885, 50,  479, 502, 181, 164,
                                                292, 832, 657, 512, 528, 588, 716, 965, 195, 106, 396, 649}))
         << endl;
}

//
// Created By jing At 2026-05-22 01:56
//
