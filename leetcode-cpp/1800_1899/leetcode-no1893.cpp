// problem:
// https://leetcode.cn/problems/check-if-all-the-integers-in-a-range-are-covered/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>> &ranges, int left, int right) {
        ranges::sort(ranges, [](const auto &a, const auto &b) { return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1]; });
        int n = ranges.size(), mx = ranges[0][1], mn = ranges[0][0];
        for (int i = 0; i < n; ++i) {
            if (ranges[i][0] > mx + 1 and left < ranges[i][0] and right > mx) return false;
            mx = max(mx, ranges[i][1]);
        }
        if (left < mn or right > mx) return false;
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.isCovered(temp_vector({temp_vector({1, 2}), temp_vector({3, 4}), temp_vector({5, 6})}), 2, 5) << endl;
    cout << test.isCovered(temp_vector({temp_vector({3, 3}), temp_vector({1, 1})}), 3, 3) << endl;
    cout << test.isCovered(temp_vector({temp_vector({1, 10}), temp_vector({10, 20})}), 21, 21) << endl;
    cout << test.isCovered(temp_vector({temp_vector({50, 50})}), 50, 50) << endl;
    cout << test.isCovered(
            temp_vector({temp_vector({25, 42}), temp_vector({7, 14}), temp_vector({2, 32}), temp_vector({25, 28}),
                         temp_vector({39, 49}), temp_vector({1, 50}), temp_vector({29, 45}), temp_vector({18, 47})}),
            15, 38)
         << endl;
}

//
// Created By jing At 2026-06-05 15:50
//
