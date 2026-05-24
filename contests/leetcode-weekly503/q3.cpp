// problem: https://leetcode.cn/contest/weekly-contest-503/problems/minimum-operations-to-sort-a-permutation/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

    class Solution {
    public:
        int minOperations(vector<int> &nums) {
            bool descend = true, ascend = true;
            int n = nums.size();
            int start = ranges::find(nums, 0) - nums.begin();
            for (int i = 0; i < n; ++i) {
                int cura = nums[(start + i) % n];
                if (cura != i) {
                    ascend = false;
                }
                int curd = nums[(start - i + n) % n];
                if (curd != i) {
                    descend = false;
                }
            }
            if (not(ascend or descend)) {
                return -1;
            }
            if (ascend) {
                return min(start, n - start + 2);
            }
            if (descend) {
                return min(start + 2, n - start);
            }
            return -1;
        }
    };

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minOperations(temp_vector({0, 2, 1})) << endl;
}

//
// Created By ASUS At 2026-05-24 10:54
//
