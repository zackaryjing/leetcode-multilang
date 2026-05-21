// problem: https://leetcode.cn/problems/minimum-amount-of-time-to-fill-cups/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int fillCups(vector<int> &amount) {
        ranges::sort(amount);
        if (amount[2] > amount[1] + amount[0]) return amount[2];
        return (amount[2] + amount[1] + amount[0] + 1) / 2;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.fillCups(temp_vector({1, 4, 2})) << endl;
    cout << test.fillCups(temp_vector({5, 4, 4})) << endl;
    cout << test.fillCups(temp_vector({5, 0, 0})) << endl;
}

//
// Created By jing At 2026-05-12 21:51
//
