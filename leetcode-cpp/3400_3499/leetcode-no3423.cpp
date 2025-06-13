// problem: https://leetcode.cn/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/?envType=daily-question&envId=2025-06-12
#include <iostream>
#include <vector>
#include <numeric>

#include "../utils/vector_helper.h"
using namespace std;


class Solution2 {
public:
    // [WA] cannot use reduce instead of accumulate, reduce doesn't guarantee sequential execution.
    int maxAdjacentDistance(vector<int> &nums) {
        int res = 0;
        reduce(nums.begin(), nums.end(), nums.back(), [&res](const int &first, const int &second) {
            res = max(res, abs(first - second));
            return second;
        });
        return res;
    }
};

class Solution {
public:
    int maxAdjacentDistance(vector<int> &nums) {
        int res = 0;
        accumulate(nums.begin(), nums.end(), nums.back(), [&res](const int &first, const int &second) {
            res = max(res, abs(first - second));
            return second;
        });
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxAdjacentDistance(temp_vector({-5, -10, -5})) << endl;
}

//
// Created By Zackary At 2025-06-12 09:29:32
//
