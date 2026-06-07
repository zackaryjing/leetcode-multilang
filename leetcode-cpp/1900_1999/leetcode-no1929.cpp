// problem:  https://leetcode.cn/problems/concatenation-of-array/?envType=problem-list-v2&envId=FeuPdeiM
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        nums.insert(nums.end(),nums.begin(), nums.end());
        return nums;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
}

//
// Created By jing At 2026-06-04 15:41
//