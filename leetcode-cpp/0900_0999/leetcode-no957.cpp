// problem: https://leetcode.cn/problems/prison-cells-after-n-days/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;


class Solution {
public:
    vector<int> prisonAfterNDays(vector<int> &cells, int n) {
        unsigned num = 0;
        if (n != 0) {
            for (int i = 0; i < 8; ++i)
                num += cells[i] << i;
            const unsigned int mask = 0b01111110u;
            for (int i = 0; i < 14 + (n % 14); ++i)
                num = (~(num << 1) ^ (num >> 1)) & mask;
            for (int i = 0; i < 8; ++i)
                cells[i] = (num >> i) & 1;
        }
        return cells;
    }
};


class Solution2 {
public:
    vector<int> prisonAfterNDays(vector<int> &cells, int n) {
        unsigned num = 0;
        if (n == 0) {
            return cells;
        }
        for (int i = 0; i < 8; ++i) {
            num += cells[i] << i;
        }
        const unsigned int mask = 0b01111110u;
        for (int i = 0; i < 14 + (n % 14); ++i) {
            num = (~(num << 1) ^ (num >> 1)) & mask;
        }
        vector<int> res(8);
        for (int i = 0; i < 8; ++i) {
            res[i] = (num >> i) & 1;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.prisonAfterNDays(temp_vector({0, 1, 0, 1, 1, 0, 0, 1}), 7));
    show_vector(test.prisonAfterNDays(temp_vector({1, 0, 0, 1, 0, 0, 1, 0}), 1000000000));
    show_vector(test.prisonAfterNDays(temp_vector({1, 1, 0, 1, 1, 0, 0, 1}), 300663720));
}

//
// Created By jing At 2025-10-28 00:11
//
