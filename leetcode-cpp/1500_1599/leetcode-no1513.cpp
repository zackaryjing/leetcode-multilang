// problem:
// https://leetcode.cn/problems/number-of-substrings-with-only-1s/description/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int numSub(string s) {
        const long long mod = 1000000007;
        long long cur = 0, res = 0;
        for (const auto &c: s) {
            if (c == '1') {
                cur++;
            } else {
                res = (res + (cur * (cur + 1) >> 1)) % mod;
                cur = 0;
            }
        }
        res = (res + cur * (cur + 1) / 2) % mod;
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.numSub("0110111") << endl;
}

//
// Created By jing At 2026-06-09 20:23
//
