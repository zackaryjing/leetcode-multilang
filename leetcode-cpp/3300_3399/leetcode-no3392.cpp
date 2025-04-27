// problem: https://leetcode.cn/problems/count-subarrays-of-length-three-with-a-condition/?envType=daily-question&envId=2025-04-27
#include <iostream>
#include <vector>

#include "../utils/vector_helper.h"
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int> &nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 2; i < n; i++) {
            res += 2 * (nums[i] + nums[i - 2]) == nums[i - 1] ? 1 : 0;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.countSubarrays(temp_vector<int>({1, 2, 1, 4, 1})) << endl;
}

//
// Created By Zackary At 2025-04-27 12:55:55
//
