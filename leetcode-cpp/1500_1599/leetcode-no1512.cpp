// problem: https://leetcode.cn/problems/number-of-good-pairs/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int> &nums) {
        unsigned char cnts[101] = { };
        for (int i = 0; i < nums.size(); ++i) {
            cnts[nums[i]]++;
        }
        int res = 0;
        for (auto cnt: cnts) {
            res += cnt * (cnt - 1) / 2;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.numIdenticalPairs(temp_vector({1, 2, 3, 1, 1, 3})) << endl;
}

//
// Created By ASUS At 2026-04-13 23:53
//
