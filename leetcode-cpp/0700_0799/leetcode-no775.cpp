// problem: https://leetcode.cn/problems/global-and-local-inversions/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    bool isIdealPermutation(vector<int> &nums) {
        // more universal
        int n = nums.size();
        int mn = INT_MAX;
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] > mn) {
                return false;
            }
            mn = min(mn, nums[i + 1]);
        }
        return true;
    }
};

class Solution2 {
public:
    bool isIdealPermutation(vector<int> &nums) {
        // depend on nums distribution
        for (int i = 0; i < nums.size(); ++i) {
            if (abs(nums[i] - i) > 1) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.isIdealPermutation(temp_vector({10, 100, 1000})) << endl;
    cout << test.isIdealPermutation(temp_vector({1, 0, 2})) << endl;
    cout << test.isIdealPermutation(temp_vector({1, 2, 0})) << endl;
}

//
// Created By jing At 2025-10-27 17:27
//
