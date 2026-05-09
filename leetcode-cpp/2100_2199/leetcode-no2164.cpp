// problem: https://leetcode.cn/problems/sort-even-and-odd-indices-independently/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    vector<int> sortEvenOdd(vector<int> &nums) {
        int n = (nums.size() + 1) / 2;
        vector<int> even, odd;
        even.reserve(n), odd.reserve(n);
        for (int i = 0; i < nums.size(); ++i) {
            if (i % 2 == 0)
                even.push_back(nums[i]);
            else
                odd.push_back(nums[i]);
        }
        ranges::sort(even);
        ranges::sort(odd);
        ranges::reverse(odd);
        for (int i = 0; i < nums.size(); ++i) {
            if (i % 2 == 0)
                nums[i] = even[i / 2];
            else
                nums[i] = odd[i / 2];
        }
        return nums;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.sortEvenOdd(temp_vector({4, 1, 2, 3})));
}

//
// Created By jing At 2026-05-03 18:24
//
