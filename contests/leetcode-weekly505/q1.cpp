// problem: https://leetcode.cn/problems/sum-of-compatible-numbers-in-range-i/description/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int res = 0;
        for (int i = max(n - k, 1); i <= n + k; ++i) {
            if ((i & n) == 0) {
                res += i;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.sumOfGoodIntegers(2, 3) << endl;
    cout << test.sumOfGoodIntegers(5, 1) << endl;
}

//
// Created By ASUS At 2026-06-07 10:32
//
