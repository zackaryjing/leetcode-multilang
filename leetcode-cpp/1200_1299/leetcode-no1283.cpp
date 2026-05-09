// problem:
// https://leetcode.cn/problems/find-the-smallest-divisor-given-a-threshold/description/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int> &nums, int threshold) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long left = max(sum / (long long) threshold, 1LL);
        int right = *ranges::max_element(nums);
        const auto ceil_divide = [](int a, int b) -> int { return (a + b - 1) / b; };
        const auto check = [&](int x) {
            int s = 0;
            for (auto num: nums) {
                s += ceil_divide(num, x);
            }
            return s <= threshold;
        };
        while (left < right) {
            int mid = (left + right) / 2;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.smallestDivisor(temp_vector({1, 2, 5, 9}), 6) << endl;
    cout << test.smallestDivisor(temp_vector({44, 22, 33, 11, 1}), 5) << endl;
    cout << test.smallestDivisor(temp_vector({21212, 10101, 12121}), 1000000) << endl;
}

//
// Created By jing At 2026-05-05 17:17
//
