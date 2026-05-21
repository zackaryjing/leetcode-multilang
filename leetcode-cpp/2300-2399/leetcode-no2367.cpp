// problem: https://leetcode.cn/problems/number-of-arithmetic-triplets/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <c++/14/unordered_set>
#include <iostream>
#include <ranges>
#include <vector>

#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int arithmeticTriplets(vector<int> &nums, int diff) {
        pmr::unordered_set<int> numset(nums.begin(), nums.end());
        int res = 0;
        for (const auto num: nums) {
            if (numset.contains(num + diff) and numset.contains(num + (diff << 1))) {
                res++;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.arithmeticTriplets(temp_vector({0, 1, 4, 6, 7, 10}), 3) << endl;
}

//
// Created By jing At 2026-05-07 20:35
//
