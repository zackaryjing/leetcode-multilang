// problem:
// https://leetcode.cn/problems/minimum-number-of-k-consecutive-bit-flips/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <format>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> diff(n + k + 1);
        int flipCnt = 0;
        int cur = 0;
        for (int i = 0; i <= n - k; ++i) {
            cur += diff[i];
            if (cur % 2 == 0 xor nums[i] == 1) {
                flipCnt++;
                ++diff[i + 1];
                --diff[i + k];
            }
        }
        for (int i = n - k + 1; i < n; ++i) {
            cur += diff[i];
            if (cur % 2 == 0 xor nums[i] == 1) return -1;
        }
        return flipCnt;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minKBitFlips(temp_vector({0, 0, 0, 1, 0, 1, 1, 0}), 3) << endl;
}

//
// Created By ASUS At 2026-07-09 23:39
//
