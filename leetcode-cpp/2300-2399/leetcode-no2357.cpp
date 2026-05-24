// problem: https://leetcode.cn/problems/make-array-zero-by-subtracting-equal-amounts/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <c++/15/unordered_set>
#include <iostream>
#include <ranges>
#include <vector>

#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> numbers(nums.begin(), nums.end());
        numbers.erase(0);
        return numbers.size();
    }
};

int main(int argc, char *argv[]) {
    Solution test;

}

//
// Created By jing At 2026-05-23 20:55
//