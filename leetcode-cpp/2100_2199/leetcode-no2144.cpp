// problem:
// https://leetcode.cn/problems/minimum-cost-of-buying-candies-with-discount/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int minimumCost(vector<int> &cost) {
        ranges::sort(cost);
        int res = 0;
        for (int i = cost.size() - 3; i >= 0; i -= 3) {
            res += cost[i + 1] + cost[i + 2];
        }
        if (cost.size() % 3 != 0) {
            res += cost[0];
            if (cost.size() % 3 == 2) {
                res += cost[1];
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minimumCost(temp_vector({5, 5})) << endl;
    cout << test.minimumCost(temp_vector({1, 2, 3})) << endl;
    cout << test.minimumCost(temp_vector({6, 5, 7, 9, 2, 2})) << endl;
}

//
// Created By jing At 2026-05-03 17:37
//
