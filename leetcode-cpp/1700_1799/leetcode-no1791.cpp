// problem: https://leetcode.cn/problems/find-center-of-star-graph/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>> &edges) {
        int n = edges.size() + 1;
        vector<bool> occurs(n + 1);
        for (const auto edge: edges) {
            if (occurs[edge[0]]) {
                return edge[0];
            }
            if (occurs[edge[1]]) {
                return edge[1];
            }
            occurs[edge[0]] = true;
            occurs[edge[1]] = true;
        }
        return 0;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.findCenter(temp_vector({temp_vector({1, 2}), temp_vector({2, 3}), temp_vector({4, 2})})) << endl;
    cout << test.findCenter(
            temp_vector({temp_vector({1, 2}), temp_vector({5, 1}), temp_vector({1, 3}), temp_vector({1, 4})}))
         << endl;
}

//
// Created By jing At 2026-05-11 20:04
//
