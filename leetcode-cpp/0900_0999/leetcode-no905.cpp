// problem: https://leetcode.cn/problems/sort-array-by-parity/?envType=problem-list-v2&envId=3rBpGyas
#include <iostream>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        int n = nums.size();
        while (true) {
            while (left < n - 1 and not(nums[left] & 1)) {
                // jump over even number
                left++;
            }
            while (right > 0 and nums[right] & 1) {
                // jump over odd number
                right--;
            }
            if (left >= right) { break; }
            swap(nums[left], nums[right]);
        }
        return nums;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.sortArrayByParity(temp_vector({3, 1, 2, 4})));
    show_vector(test.sortArrayByParity(temp_vector({0})));
    show_vector(test.sortArrayByParity(temp_vector({1, 3})));
}

//
// Created By Zackary At 2025-10-23 01:35:50
//
