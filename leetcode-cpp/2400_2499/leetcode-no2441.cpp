// problem:
// https://leetcode.cn/problems/largest-positive-integer-that-exists-with-its-negative/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int findMaxK(vector<int> &nums) {
        vector<int> occurs(1001);
        int res = -1;
        for (const auto num: nums) {
            const int temp = abs(num);
            occurs[temp] |= num < 0 ? 2 : 1;
            if (occurs[temp] == 3) {
                res = max(res, temp);
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.findMaxK(temp_vector({-10, 8, 6, 7, -2, -3})) << endl;
    cout << test.findMaxK(temp_vector({-1, 10, 6, 7, -7, 1})) << endl;
}

//
// Created By jing At 2026-05-15 18:58
//
