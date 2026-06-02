// problem:  https://leetcode.cn/contest/weekly-contest-485/problems/maximum-capacity-within-budget/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    int maxCapacity(vector<int> &costs, vector<int> &capacity, int budget) {
        int n = costs.size();
        vector<pair<int, int>> cocaPairs;
        cocaPairs.reserve(n);
        for (int i = 0; i < n; ++i) {
            cocaPairs.emplace_back(costs[i], capacity[i]);
        }
        ranges::sort(cocaPairs);
        vector<int> mxCapacity(budget + 1);
        vector<int> mxPos(budget + 1);
        for (int i = 0; i < n; ++i) {
            auto &temp = mxCapacity[cocaPairs[i].first];
            if (cocaPairs[i].second > temp) {
                temp = cocaPairs[i].second;
                mxPos[cocaPairs[i].first] = i;
            }
        }
        for (int i = 1; i < n; ++i) {
            cocaPairs[i] = max(cocaPairs[i], cocaPairs[i - 1]);
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, cocaPairs[i].second + mxCapacity[budget - cocaPairs[i].first]);
        }
        return res;
    }
};


class Solution {
public:
    int maxCapacity(vector<int> &costs, vector<int> &capacity, int budget) {
        budget--;
        int n = costs.size();
        vector<int> mxCapacity(budget + 1);
        vector<int> mxPos(budget + 1);
        auto smxCapacity = mxCapacity;
        for (int i = 0; i < n; ++i) {
            if (costs[i] > budget) {
                continue;
            }
            if (capacity[i] > mxCapacity[costs[i]]) {
                mxCapacity[costs[i]] = capacity[i];
                mxPos[costs[i]] = i;
            }
        }
        int mx = 0, smx = 0;
        for (int j = 1; j <= budget; ++j) {
            if (mxCapacity[j] >= mx) {
                smx = mx;
                mx = mxCapacity[j];
            } else if (mxCapacity[j] > smx) {
                smx = mxCapacity[j];
                mxPos[j] = mxPos[j - 1];
            } else {
                mxPos[j] = mxPos[j - 1];
            }
            mxCapacity[j] = mx;
            smxCapacity[j] = smx;
        }
        int res = mx;
        for (int i = 0; i < n; ++i) {
            if (budget > costs[i]) {
                if (mxPos[budget - costs[i]] == i) {
                    res = max(res, smxCapacity[budget - costs[i]] + capacity[i]);
                } else {
                    res = max(res, mxCapacity[budget - costs[i]] + capacity[i]);
                }
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxCapacity(temp_vector({4, 8, 5, 3}), temp_vector({1, 5, 2, 7}), 8) << endl;
    cout << test.maxCapacity(temp_vector({3, 5, 7, 4}), temp_vector({2, 4, 3, 6}), 7) << endl;
}

//
// Created By jing At 2026-06-02 16:01
//
