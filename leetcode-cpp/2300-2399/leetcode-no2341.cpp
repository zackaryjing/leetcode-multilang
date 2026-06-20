// problem: https://leetcode.cn/problems/maximum-number-of-pairs-in-array/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int> &nums) {
        vector<bool> occured(101);
        int pairs = 0;
        for (auto num: nums) {
            occured[num] = !occured[num];
            if (not occured[num]) {
                pairs++;
            }
        }
        return {pairs, static_cast<int>(nums.size() - pairs * 2)};
    }
};

int main(int argc, char *argv[]) {
    Solution test;
}

//
// Created By jing At 2026-06-19 20:29
//
