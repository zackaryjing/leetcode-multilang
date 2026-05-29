// problem: https://leetcode.cn/problems/sign-of-the-product-of-an-array/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int arraySign(vector<int> &nums) {
        int res = 1;
        for (const auto num: nums) {
            if (num == 0) return 0;
            res ^= (num < 0);
        }
        return (res << 1) - 1;
    }
};

int main(int argc, char *argv[]) {
    Solution test;

}

//
// Created By jing At 2026-05-28 18:22
//
