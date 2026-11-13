// problem:
// https://leetcode.cn/problems/longest-even-odd-subarray-with-threshold/description/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int> &nums, int threshold) {
        int mx = 0, cur = 0, last = 1;
        for (auto num: nums) {
            if (num > threshold) {
                cur = 0, last = 1;
                continue;
            }
            if (num % 2 == 0 ^ last % 2 == 0) {
                cur++;
                mx = max(cur, mx);
            } else {
                if (num % 2 == 0) {
                    cur = 1;
                } else {
                    cur = 0;
                }
            }
            last = num;
        }
        return mx;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.longestAlternatingSubarray(temp_vector({3, 2, 5, 4}), 5) << endl;
    cout << test.longestAlternatingSubarray(temp_vector({1, 2}), 2) << endl;
    cout << test.longestAlternatingSubarray(temp_vector({2, 3, 4, 5}), 4) << endl;
    cout << test.longestAlternatingSubarray(temp_vector({8, 4}), 6) << endl;
}

//
// Created By ASUS At 2026-07-11 15:26
//
