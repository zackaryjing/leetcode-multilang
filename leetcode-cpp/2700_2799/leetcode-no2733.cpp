// problem:  https://leetcode.cn/problems/neither-minimum-nor-maximum/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int findNonMinOrMax(vector<int> &nums) {
        int mn = nums[0], mx = nums[0];
        int res = -1;
        for (int num: nums) {
            if (num >= mx) {
                if (num > mx) res = mx;
                mx = num;
            } else if (num <= mn) {
                if (num < mn) res = mn;
                mn = num;
            } else {
                res = num;
            }
        }
        return (res != mn and res != mx) ? res : -1;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
}

//
// Created By ASUS At 2026-06-22 22:54
//
