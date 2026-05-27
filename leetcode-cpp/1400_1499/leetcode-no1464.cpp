// problem:
// https://leetcode.cn/problems/maximum-product-of-two-elements-in-an-array/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        auto [mx1, mx2] = ranges::fold_left(nums, pair{INT_MIN, INT_MIN}, [](pair<int, int> acc, int x) {
            auto [a, b] = acc;
            if (x >= a) return pair{x, a};
            if (x > b) return pair{a, x};
            return acc;
        });
        return (mx1 - 1) * (mx2 - 1);
    }
};

int main(int argc, char *argv[]) {
    Solution test;
}

//
// Created By jing At 2026-05-27 17:33
//
