// problem: https://leetcode.cn/problems/maximum-candies-you-can-get-from-boxes/?envType=daily-question&envId=2025-06-03
#include <iostream>
#include <deque>
#include <vector>

#include "../utils/vector_helper.h"
using namespace std;

// time spent: 1:20:00
class Solution {
public:
    int maxCandies(vector<int> &status, vector<int> &candies, vector<vector<int>> &keys,
                   vector<vector<int>> &containedBoxes, vector<int> &initialBoxes) {
        std::pmr::deque<int> toVis;
        for (auto box: initialBoxes) {
            toVis.push_back(box);
        }
        int res = 0;
        deque<int> noKeys;
        while (not toVis.empty()) {
            int cur = toVis.front();
            toVis.pop_front();
            if (status[cur]) {
                res += candies[cur];
                for (const auto box: containedBoxes[cur]) {
                    toVis.push_back(box);
                }
                for (const auto key: keys[cur]) {
                    status[key] = 1;
                }
            } else {
                noKeys.push_back(cur);
            }
            if (toVis.empty() && not noKeys.empty()) {
                int m = static_cast<int>(noKeys.size());
                for (int i = 0; i < m; ++i) {
                    int head = noKeys.front();
                    noKeys.pop_front();
                    if (status[head]) {
                        toVis.push_back(head);
                    } else {
                        noKeys.push_back(head);
                    }
                }
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxCandies(temp_vector({1, 0, 1, 0}), temp_vector({7, 5, 4, 100}),
                            temp_vector<vector<int>>({{}, {}, {1}, {}}),
                            temp_vector({{1, 2}, {3}, {}, {}}), temp_vector({0})) << endl;
    cout << test.maxCandies(
            temp_vector({1, 0, 0, 0, 0, 0}),
            temp_vector({1, 1, 1, 1, 1, 1}),
            temp_vector({{1, 2, 3, 4, 5}, {}, {}, {}, {}, {}}),
            temp_vector({{1, 2, 3, 4, 5}, {}, {}, {}, {}, {}}),
            temp_vector({0})
            ) << endl;
}

//
// Created By Zackary At 2025-06-03 13:38:20
//
