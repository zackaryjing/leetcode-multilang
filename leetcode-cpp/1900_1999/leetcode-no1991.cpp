// problem: https://leetcode.cn/problems/find-the-middle-index-in-array/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int cur = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (cur == sum - cur - nums[i]) {
                return i;
            }
            cur += nums[i];
        }
        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.findMiddleIndex(temp_vector({2, 3, -1, 8, 4})) << endl;
}

//
// Created By jing At 2026-06-05 17:04
//
