// problem:  https://leetcode.cn/problems/number-of-adjacent-elements-with-the-same-color/
#include <iostream>
#include <unordered_set>
#include <vector>

#include "../utils/vector_helper.h"
using namespace std;

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>> &queries) {
        vector<int> colors(n + 2);
        vector<int> res;
        res.reserve(queries.size());
        int cur = 0;
        for (const auto &query: queries) {
            const int query_pos = query[0];
            const int query_color = query[1];
            const int first = colors[query_pos];
            int &mid = colors[query_pos + 1];
            const int second = colors[query_pos + 2];

            if (mid != 0) {
                if (first == mid) {
                    --cur;
                }
                if (second == mid) {
                    --cur;
                }
            }
            mid = query_color;
            if (first == query_color) {
                ++cur;
            }
            if (second == query_color) {
                ++cur;
            }
            res.push_back(cur);
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    // show_vector(test.colorTheArray(4, temp_vector<vector<int>>({{0, 2}, {1, 2}, {3, 1}, {1, 1}, {2, 1}})));
    // show_vector(test.colorTheArray(1, temp_vector<vector<int>>({{0, 100000}})));
    show_vector(test.colorTheArray(8, temp_vector<vector<int>>({{6, 2}, {2, 1}, {0, 6}, {0, 1}, {0, 4}, {0, 1}, {5, 7},
                                                                {5, 3}, {7, 6}, {6, 7}, {0, 4}, {4, 6}, {4, 2}, {3, 7},
                                                                {4, 4}, {5, 1}})));
}

//
// Created By Zackary At 2025-04-26 15:58:43
//
