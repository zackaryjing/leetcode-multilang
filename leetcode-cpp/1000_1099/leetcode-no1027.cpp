// problem: https://leetcode.cn/problems/longest-arithmetic-subsequence/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <deque>
#include <unordered_set>

#include "../utils/vector_helper.h"
using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int> &nums) {
        auto [mins,maxs] = ranges::minmax_element(nums);
        int diff = *maxs - *mins;
        int res = 1;
        for (int d = -diff; d <= diff; ++d) {
            vector<int> cnts(*maxs + 1);
            for (auto num: nums) {
                if (num - d >= 0 and num - d <= *maxs and cnts[num - d] > 0) {
                    cnts[num] = max(cnts[num - d] + 1, cnts[num]);
                    res = max(res, cnts[num]);
                } else {
                    cnts[num] = max(cnts[num], 1);
                }
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.longestArithSeqLength(temp_vector({3, 6, 9, 12})) << endl;
    cout << test.longestArithSeqLength(temp_vector({9, 4, 7, 2, 10})) << endl;
    cout << test.longestArithSeqLength(temp_vector({3, 6, 9, 12})) << endl;
}

//
// Created By Zackary At 2025-06-03 16:00:34
//
