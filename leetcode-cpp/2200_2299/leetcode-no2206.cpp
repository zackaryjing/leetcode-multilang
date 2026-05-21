// problem: https://leetcode.cn/problems/divide-array-into-equal-pairs/
#include <algorithm>
#include <c++/14/unordered_map>
#include <iostream>
#include <ranges>
#include <vector>

#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    bool divideArray(vector<int> &nums) {
        vector<int> cnts(501);
        for (const auto num: nums) cnts[num]++;
        for (const auto v: cnts)
            if (v & 1) return false;
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.divideArray(temp_vector({3, 2, 3, 2, 2, 2})) << endl;
    cout << test.divideArray(temp_vector({1, 2, 3, 4})) << endl;
}

//
// Created By jing At 2026-05-22 00:18
//
