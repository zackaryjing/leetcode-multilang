// problem:
// https://leetcode.cn/problems/minimum-value-to-get-positive-step-by-step-sum/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int minStartValue(vector<int> &nums) {
        int base = 0;
        int res = 1;
        for (const auto num: nums) {
            base += num;
            res = max(-base + 1, res);
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minStartValue(temp_vector({-3, 2, -3, 4, 2})) << endl;
}

//
// Created By jing At 2026-01-06 18:44
//
