// problem: https://leetcode.cn/problems/find-subarrays-with-equal-sum/description/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_set>
#include <vector>

#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> occurs;
        for (int i = 1;i < nums.size();++i) {
            int s = nums[i] + nums[i - 1];
            if (not occurs.insert(s).second) {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution test;

}

//
// Created By jing At 2026-05-13 01:13
//