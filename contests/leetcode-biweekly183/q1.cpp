// problem: https://leetcode.cn/contest/biweekly-contest-183/problems/minimum-swaps-to-move-zeros-to-end/description/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int minimumSwaps(vector<int> &nums) {
        int n = nums.size();
        int zcnt = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] == 0) {
                zcnt += 1;
            }
        }
        int nzcnt = 0;
        for (int i = n - 1; i >= n - zcnt; --i) {
            if (nums[i] != 0) {
                nzcnt += 1;
            }
        }
        return nzcnt;
    }
};

int main(int argc, char *argv[]) {
    Solution test;

}

//
// Created By jing At 2026-05-23 22:30
//
