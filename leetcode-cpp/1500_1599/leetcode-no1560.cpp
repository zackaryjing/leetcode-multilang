// problem: https://leetcode.cn/problems/most-visited-sector-in-a-circular-track/?envType=problem-list-v2&envId=OOhHf3Bc
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    vector<int> mostVisited(int n, vector<int> &rounds) {
        auto res = vector<int>();
        for (int i = 0; i < (rounds.back() + n - rounds.front()) % n + 1; ++i) {
            res.push_back((i + rounds.front() - 1) % n + 1);
        }
        ranges::sort(res);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.mostVisited(7, temp_vector({1, 3, 5, 7})));
    show_vector(test.mostVisited(2, temp_vector({2, 1, 2, 1, 2, 1, 2, 1, 2})));
    show_vector(test.mostVisited(4, temp_vector({1, 3, 1, 2})));
    show_vector(test.mostVisited(8, temp_vector({4, 2})));
}

//
// Created By ASUS At 2026-02-06 20:51
//
