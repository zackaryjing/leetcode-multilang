// problem: https://leetcode.cn/problems/maximize-the-profit-as-the-salesman/
#include <iostream>
#include <vector>
#include <numeric>
#include <ranges>
#include <algorithm>
#include "../utils/vector_helper.h"
using namespace std;


class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>> &offers) {
        int m = offers.size();
        vector<int> costs(m);
        ranges::sort(offers, [](const auto &a, const auto &b) { return a[1] < b[1]; });
        int last = 0;
        for (int i = 0; i < m; ++i) {
            const auto &offer = offers[i];
            costs[i] = last;
            costs[i] = max(costs[i], offer[2]);
            auto p = ranges::partition_point(offers, [&offer](const vector<int> &a) {
                return a[1] < offer[0];
            });
            if (p > offers.begin() or p == offers.begin() and offers[0][1] < offer[0]) {
                costs[i] = max(costs[i], costs[p - offers.begin() - 1] + offer[2]);
            }
            last = costs[i];
        }
        return costs[m - 1];
    }
};


class Solution_2 {
    // [TLE]
public:
    int maximizeTheProfit(int n, vector<vector<int>> &offers) {
        // vector<int> costs(n);
        int m = offers.size();
        vector<int> costs(m);
        ranges::sort(offers, [](const auto &a, const auto &b) { return a[1] < b[1]; });
        int last = 0;
        for (int i = 0; i < m; ++i) {
            int j = i;
            const auto &offer = offers[i];
            costs[i] = last;
            costs[i] = max(costs[i], offer[2]);
            while (j >= 0) {
                if (offer[0] > offers[j][1]) {
                    costs[i] = max(costs[i], costs[j] + offer[2]);
                    break;
                }
                --j;
            }
            last = costs[i];
        }
        return costs[m - 1];
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maximizeTheProfit(5, temp_vector({temp_vector({0, 0, 1}), temp_vector({0, 2, 2}),
                                                   temp_vector({1, 3, 2})})) << endl;
    cout << test.maximizeTheProfit(5, temp_vector({temp_vector({0, 0, 1}), temp_vector({0, 2, 10}),
                                                   temp_vector({1, 3, 2})})) << endl;
}

//
// Created By Zackary At 2025-06-15 23:51:56
//
