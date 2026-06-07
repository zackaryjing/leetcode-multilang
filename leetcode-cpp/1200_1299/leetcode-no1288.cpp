// problem:  https://leetcode.cn/problems/remove-covered-intervals/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals) {
        ranges::sort(intervals, [](const auto& a, const auto& b) { return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1]; });
        int lastEnd = 0, res = intervals.size();
        for (const auto &interval: intervals) {
            if (interval[1] <= lastEnd) {
                res--;
            } else {
                lastEnd = interval[1];
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.removeCoveredIntervals(temp_vector({temp_vector({1,4}),temp_vector({3,6}),temp_vector({2,8})})) << endl;
    cout << test.removeCoveredIntervals(temp_vector({temp_vector({1,2}),temp_vector({1,4}),temp_vector({3,4})})) << endl;

}

//
// Created By jing At 2026-06-03 16:02
//
