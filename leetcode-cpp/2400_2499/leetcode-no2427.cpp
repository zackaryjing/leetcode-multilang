// problem: https://leetcode.cn/problems/number-of-common-factors/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <cmath>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int commonFactors(int a, int b) {
        const auto gcd = [](int a, int b) {
            while (b != 0) {
                auto temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        };
        int r = gcd(a, b);
        int res = 2;
        int k = sqrt(r);
        for (int j = 2; j <= k; ++j) {
            if (r % j == 0) res += 2;
        }
        res -= (k * k) == r;
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.commonFactors(25, 30) << endl;
    cout << test.commonFactors(12, 6) << endl;
}

//
// Created By jing At 2026-06-19 20:50
//
