// problem: https://leetcode.cn/problems/minimum-cost-for-tickets/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int mincostTickets(vector<int> &days, vector<int> &costs) {
        vector<int> mnCosts(366);
        int m = days.size();
        int index = 0;
        for (int i = 1; i < 366; ++i) {
            if (index >= m or i != days[index]) {
                mnCosts[i] = mnCosts[i - 1];
            } else {
                ++index;
                mnCosts[i] = min({mnCosts[i - 1] + costs[0], //
                                  (i > 6 ? mnCosts[i - 7] : 0) + costs[1], //
                                  (i > 29 ? mnCosts[i - 30] : 0) + costs[2]});
            }
        }
        return mnCosts[365];
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.mincostTickets(temp_vector({1, 4, 6, 7, 8, 20}), temp_vector({2, 7, 15})) << endl;
    cout << test.mincostTickets(temp_vector({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31}), temp_vector({2, 7, 15})) << endl;
}

//
// Created By jing At 2026-05-28 20:19
//
