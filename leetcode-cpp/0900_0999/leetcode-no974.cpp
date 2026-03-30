// problem: https://leetcode.cn/problems/subarray-sums-divisible-by-k/?envType=problem-list-v2&envId=3rBpGyas
#include <iostream>
#include <ranges>
#include <algorithm>
#include <numeric>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    int subarraysDivByK(vector<int> &nums, int k) {
        inclusive_scan(nums.begin(), nums.end(), nums.begin(), [&](auto a, auto b) {
            return ((a + b) % k + k) % k;
        }, 0);
        vector<int> cnts(k);
        cnts[0] = 1;
        for (const auto num: nums) {
            cnts[num]++;
        }
        int res = 0;
        for (const auto cnt: cnts) {
            res += cnt * (cnt - 1) / 2;
        }
        return res;
    }
};


class Solution3 {
public:
    int subarraysDivByK(vector<int> &nums, int k) {
        int sum = 0, offset = (10000 / k + 1) * k;
        vector<int> cnts(k);
        for (const auto num: nums) {
            cnts[sum % k]++;
            sum += num + offset;
        }
        cnts[sum % k]++;
        int res = 0;
        for (const auto cnt: cnts) {
            res += (cnt * (cnt - 1)) >> 1;
        }
        return res;
    }
};


class Solution {
public:
    int subarraysDivByK(vector<int> &nums, int k) {
        int sum = 0, res = 0, offset = (10000 / k + 1) * k;
        vector<int> counts(k);
        for (const int num: nums)
            res += ++counts[sum % k] - 1, sum += num + offset;
        res += ++counts[sum % k] - 1;
        return res;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.subarraysDivByK(temp_vector({4, 5, 0, -2, -3, 1}), 5) << endl;;
    cout << test.subarraysDivByK(temp_vector({-5}), 5) << endl;;
}

//
// Created By ASUS At 2026-02-12 20:29
//
