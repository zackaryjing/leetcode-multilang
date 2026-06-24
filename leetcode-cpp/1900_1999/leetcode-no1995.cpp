// problem: https://leetcode.cn/problems/count-special-quadruplets/description/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int countQuadruplets(vector<int> &nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (int k = 0; k < j; ++k) {
                    for (int l = 0; l < k; ++l) {
                        if (nums[l] + nums[k] + nums[j] == nums[i]) {
                            res++;
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
}

//
// Created By jing At 2026-06-24 12:07
//
