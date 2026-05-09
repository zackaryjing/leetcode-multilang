// problem: https://leetcode.cn/problems/maximum-ascending-subarray-sum/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int> &nums) {
        int mx = -1, res = 0, temp = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > mx) {
                temp += nums[i];
            } else {
                temp = nums[i];
            }
            mx = nums[i];
            res = max(res, temp);
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxAscendingSum(temp_vector({10, 20, 30, 5, 10, 50})) << endl;
    cout << test.maxAscendingSum(temp_vector({10, 20, 30, 40, 50})) << endl;
    cout << test.maxAscendingSum(temp_vector({12, 17, 15, 13, 10, 11, 12})) << endl;
}

//
// Created By ASUS At 2026-05-09 19:56
//
