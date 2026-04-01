// problem: https://leetcode.cn/problems/sort-array-by-increasing-frequency/description/
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int> &nums) {
        unordered_map<int, int> cnts;
        const int offset = 1000000;
        for (auto num: nums) {
            cnts[num]++;
        }
        ranges::sort(nums, [&](auto &a, auto &b) { return cnts[a] * offset - a < cnts[b] * offset - b; });
        return nums;
    }
};


int main(int argc, char *argv[]) {
    Solution s;
    // vector<int> test = {1,1,2,2,2,3};
    vector<int> test = {2, 3, 1, 3, 2};
    auto res = s.frequencySort(test);
    for (auto num: res) {
        cout << num << ", ";
    }
    cout << endl;
}


//
// Created By jing At 2026-04-01 23:26
//
