// problem: https://leetcode.cn/problems/number-of-unequal-triplets-in-array/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int unequalTriplets(vector<int> &nums) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            const int &a = nums[i];
            for (int j = i + 1; j < n; ++j) {
                const int &b = nums[j];
                for (int k = j + 1; k < n; ++k) {
                    const int &c = nums[k];
                    if (a != b and a != c and b != c) res += 1;
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
// Created By jing At 2026-05-24 22:41
//
