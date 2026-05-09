// problem: https://leetcode.cn/contest/biweekly-contest-182/problems/minimum-generations-to-target-point/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_set>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;


class Solution {
public:
    int minGenerations(vector<vector<int>> &points, vector<int> &target) {
        unordered_set<int> allpoints;
        for (auto point: points) {
            int x = point[0], y = point[1], z = point[2];
            allpoints.insert(x << 9 | (y << 5) | (z << 1));
        }
        int tp = (target[0] << 9) | (target[1] << 5) | (target[2] << 1);
        if (allpoints.contains(tp))
            return 0;
        int mask = 0b111011101110;
        int index = 1;
        while (true) {
            int oldsize = allpoints.size();
            unordered_set newPoints = allpoints;
            for (const auto point1: allpoints) {
                for (const auto point2: allpoints) {
                    int point3 = ((point1 + point2) >> 1) & mask;
                    if (point3 == tp) {
                        return index;
                    }
                    newPoints.insert(point3);
                }
            }
            if (newPoints.size() == oldsize) {
                return -1;
            }
            allpoints = newPoints;
            index++;
        }
        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minGenerations(temp_vector({temp_vector({0, 0, 0}), temp_vector({5, 5, 5})}), temp_vector({1, 1, 1}))
         << endl;
}

//
// Created By jing At 2026-05-09 23:03
//
