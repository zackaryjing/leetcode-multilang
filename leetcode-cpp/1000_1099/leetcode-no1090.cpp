// problem: https://leetcode.cn/problems/largest-values-from-labels/description/?envType=problem-list-v2&envId=3rBpGyas

#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    int largestValsFromLabels(vector<int> &values, vector<int> &labels, int numWanted, int useLimit) {
        auto zipped = views::zip(values, labels);
        vector<pair<int, int>> v(zipped.begin(), zipped.end());
        ranges::sort(v, greater<pair<int, int>>());
        pmr::unordered_map<int, int> usedTimes;
        int res = 0, itemChosen = 0;
        for (auto &[value, l]: v) {
            if (usedTimes[l] < useLimit) {
                res += value;
                usedTimes[l]++;
                itemChosen++;
                if (itemChosen >= numWanted) {
                    break;
                }
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    test.largestValsFromLabels(temp_vector({5, 4, 3, 2, 1}), temp_vector({1, 1, 2, 2, 3}), );
}

//
// Created By jing At 2026-05-05 20:49
//
