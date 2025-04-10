// problem: https://leetcode.cn/problems/partition-equal-subset-sum/description/?envType=daily-question&envId=2025-04-07
#include <iostream>
#include <memory>
#include <numeric>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2) {
            return false;
        }
        auto half = total / 2 + 1;
        vector<bool> bag(half);
        bag[0] = true;
        int n = nums.size();
        for (int j = 0; j < n; ++j) {
            int t = nums[j];
            for (int i = half - t - 1; i >= 0; --i) {
                if (bag[i]) {
                    bag[t + i] = true;
                }
            }
        }
        // show_vector(bag);
        return bag[half - 1];
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.canPartition(*make_unique<vector<int> >(vector{1, 2, 5})) << endl;
    cout << test.canPartition(*make_unique<vector<int> >(vector{1, 5, 11, 5})) << endl;
    cout << test.canPartition(*make_unique<vector<int> >(vector{1, 2, 3, 5})) << endl;
}


//
// Created by ASUS on 2025/4/7.
//
