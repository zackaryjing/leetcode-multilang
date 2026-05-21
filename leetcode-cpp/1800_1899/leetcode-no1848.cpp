// problem: https://leetcode.cn/problems/minimum-distance-to-the-target-element/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int getMinDistance(vector<int> &nums, int target, int start) {
        const int n = nums.size();
        for (int i = 0; i <= max(n - start - 1, start); ++i) {
            if (start + i < n and nums[start + i] == target) {
                return i;
            }
            if (start - i >= 0 and nums[start - i] == target) {
                return i;
            }
        }
        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.getMinDistance(temp_vector({1, 2, 3, 4, 5}), 5, 3) << endl;
}

//
// Created By jing At 2026-05-19 14:37
//
