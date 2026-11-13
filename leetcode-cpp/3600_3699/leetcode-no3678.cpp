// problem:
// https://leetcode.cn/problems/smallest-absent-positive-greater-than-average/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int smallestAbsent(vector<int> &nums) {
        const int avg = accumulate(nums.begin(), nums.end(), 0) / int(nums.size());
        int n = nums.size();
        vector<bool> occured(n);
        int lower = max(0, avg);
        int upper = lower + 1 + n;
        for (const int num: nums)
            if (num > lower and num < upper) occured[num - lower - 1] = true;
        for (int i = lower + 1; i < upper; ++i)
            if (not occured[i - lower - 1]) return i;
        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.smallestAbsent(temp_vector({3, 5})) << endl;
    cout << test.smallestAbsent(temp_vector({-1, 1, 2})) << endl;
    cout << test.smallestAbsent(temp_vector({-84, 28, 12})) << endl;
}

//
// Created By ASUS At 2026-07-13 13:05
//
