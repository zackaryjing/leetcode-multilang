// problem:
// https://leetcode.cn/problems/maximum-value-at-a-given-index-in-a-bounded-array/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    int maxValue(int n, int index, int maxSum) {
        long long left = 1;
        long long right = maxSum;
        long long m = n - 1;
        while (left < right) {
            long long summit = (left + right + 1) / 2;
            long long cost = 0;
            if (index >= summit) {
                cost += (index - summit + 1) + (1 + summit) * summit / 2;
            } else {
                cost += (index + 1) * (summit + summit - index) / 2;
            }

            if (m >= index + summit - 1) {
                cost += (summit * (summit - 1)) / 2 + m - (index + summit - 1);
            } else {
                cost += (summit - 1 + summit - (m - index)) * (m - index) / 2;
            }
            if (cost > maxSum) {
                right = summit - 1;
            } else {
                left = summit;
            }
        }
        return left;
    }
};


class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long long left = 1, right = maxSum;
        while (left < right) {
            const long long summit = (left + right + 1) / 2;
            (index >= summit ? index - summit + 1 + (1 + summit) * summit / 2
                             : (index + 1) * (summit + summit - index) / 2) +
            (n >= index + summit ? summit * (summit - 1) / 2 + n - index - summit
                                 : (2 * summit - n + index) * (n - 1 - index) / 2) >
            maxSum
            ? right = summit - 1
            : left = summit;
        }
        return static_cast<int>(left);
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxValue(4, 2, 6) << endl;
}

//
// Created By ASUS At 2026-06-07 16:21
//
