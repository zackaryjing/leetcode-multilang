// problem:
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>> &intervals) {
        ranges::sort(intervals, [](const auto &a, const auto &b) { return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1]; });
        int mn = intervals[0][0];
        int mx = intervals[0][1];
        int m = intervals.size();
        long long cnts = mx - mn + 1;
        for (int i = 1; i < m; ++i) {
            if (intervals[i][0] <= mx + 1) {
                if (intervals[i][1] > mx) {
                    cnts += intervals[i][1] - mx;
                }
            } else {
                cnts += intervals[i][1] - intervals[i][0] + 1;
            }
            mx = max(mx, intervals[i][1]);
        }
        return ((brightness + 2) / 3) * cnts;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minEnergy(5, 6, temp_vector({temp_vector({6, 12})})) << " e 14" << endl;
    cout << test.minEnergy(2, 1, temp_vector({temp_vector({0, 0}), temp_vector({2, 2})})) << " e 2" << endl;
    cout << test.minEnergy(4,2,temp_vector({temp_vector({1,3}),temp_vector({2,4})})) << " e 4" << endl;
}

//
// Created By jing At 2026-06-06 22:29
//
