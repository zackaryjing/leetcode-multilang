// problem:
// https://leetcode.cn/problems/number-of-burgers-with-no-waste-of-ingredients/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if (tomatoSlices % 2 == 1) return {};
        int x = (tomatoSlices - 2 * cheeseSlices) / 2;
        int y = (4 * cheeseSlices - tomatoSlices) / 2;
        return x >= 0 and y >= 0 ? vector{x, y} : vector<int>{};
    }
};

int main(int argc, char *argv[]) {
    Solution test;
}

//
// Created By jing At 2026-05-05 17:13
//
