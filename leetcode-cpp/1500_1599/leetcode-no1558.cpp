// problem: https://leetcode.cn/problems/minimum-numbers-of-function-calls-to-make-target-array/?envType=problem-list-v2&envId=OOhHf3Bc
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include "../utils/vector_helper.h"
#include <bit>


using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums) {
        int res = 0, digit = 0;
        for (const auto num: nums) {
            res += popcount(static_cast<unsigned>(num));
            digit = max(digit, bit_width(static_cast<unsigned>(num)));
        }
        return max(res + digit - 1, 0);
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minOperations(temp_vector({1, 5})) << endl;
    cout << test.minOperations(temp_vector({2, 2})) << endl;
}

//
// Created By ASUS At 2026-02-06 21:06
//
