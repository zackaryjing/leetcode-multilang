// problem:
// https://leetcode.cn/problems/remove-one-element-to-make-the-array-strictly-increasing/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    bool canBeIncreasing(vector<int> &nums) {
        int n = nums.size();
        int cnts = 0;
        int pos = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] >= nums[i]) {
                cnts++;
                pos = i;
            }
            if (cnts >= 2) return false;
        }
        // cout << "here" << endl;
        // cout << "pos: " << pos << endl;
        // cout << "nums[pos - 1]: " << nums[pos - 1] << endl;
        // cout << "nums[pos]: " << nums[pos] << endl;
        if (cnts >= 1) {
            if ((pos >= 2 and nums[pos] > nums[pos - 2]) or (pos < n - 1 and nums[pos - 1] < nums[pos + 1]))
                return true;
        }
        // cout << "there" << endl;
        return cnts >= 1;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.canBeIncreasing(temp_vector({1, 2, 10, 5, 7})) << endl;
    cout << test.canBeIncreasing(temp_vector({1, 2, 3})) << endl;
}

//
// Created By jing At 2026-06-06 17:49
//
