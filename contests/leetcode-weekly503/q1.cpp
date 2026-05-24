// problem: https://leetcode.cn/contest/weekly-contest-503/problems/limit-occurrences-in-sorted-array/
#include <algorithm>
#include <iostream>
#include <map>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    vector<int> limitOccurrences(vector<int> &nums, int k) {
        int n = nums.size();
        if (n == 1)
            return nums;
        map<int, int> cnts;
        for (int num: nums) {
            cnts[num]++;
        }
        vector<int> res;
        for (auto &[key, v]: cnts) {
            res.insert(res.end(), min(v, k), key);
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.limitOccurrences(temp_vector({1, 1, 1, 2, 2, 3}), 2));
    show_vector(test.limitOccurrences(temp_vector({1, 2, 3}), 1));
    show_vector(test.limitOccurrences(temp_vector({40, 40, 40}), 1));
}

//
// Created By ASUS At 2026-05-24 10:34
//
