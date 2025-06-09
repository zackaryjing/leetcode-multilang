// problem: https://leetcode.cn/problems/relocate-marbles/description/
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "../utils/vector_helper.h"
using namespace std;

class Solution {
public:
    vector<int> relocateMarbles(vector<int> &nums, vector<int> &moveFrom, vector<int> &moveTo) {
        unordered_map<int, int> posCnt;
        int n = static_cast<int>(moveFrom.size());
        for (const auto num: nums) {
            posCnt[num]++;
        }
        for (int i = 0; i < n; ++i) {
            int from = moveFrom[i];
            int to = moveTo[i];
            if (posCnt[from] != 0 and from != to) {
                posCnt[to] += posCnt[from];
                posCnt[from] = 0;
            }
        }

        vector<int> res;
        for (const auto &[key,v]: posCnt) {
            if (v != 0) {
                res.push_back(key);
            }
        }
        ranges::sort(res);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.relocateMarbles(temp_vector({1, 6, 7, 8}), temp_vector({1, 7, 2}), temp_vector({2, 9, 5})));
    show_vector(test.relocateMarbles(temp_vector({1, 1, 3, 3}), temp_vector({1, 3}), temp_vector({2, 2})));
}

//
// Created By Zackary At 2025-06-07 23:09:51
//
