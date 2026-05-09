// problem: https://leetcode.cn/problems/min-max-game/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int minMaxGame(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; n > 2; n /= 2) {
            for (int j = 0; j < n / 2; j += 2) {
                nums[j] = min(nums[2 * j], nums[2 * j + 1]);
                nums[j + 1] = max(nums[2 * j + 2], nums[2 * j + 3]);
            }
        }
        return n >= 2 ? min(nums[0], nums[1]) : nums[0];
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minMaxGame(temp_vector({1, 3, 5, 2, 4, 8, 2, 2})) << endl;
    cout << test.minMaxGame(temp_vector({999, 939, 892, 175, 114, 464, 850, 107})) << endl;
}

//
// Created By jing At 2026-05-04 21:03
//
