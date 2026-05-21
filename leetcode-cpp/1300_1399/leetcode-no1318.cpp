// problem: https://leetcode.cn/problems/minimum-flips-to-make-a-or-b-equal-to-c/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        return popcount(((a | b) ^ c) + (static_cast<uint64_t>(a & b & ~c) << 32));
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minFlips(2, 6, 5) << endl;
    cout << test.minFlips(4, 2, 7) << endl;
}

//
// Created By ASUS At 2026-05-22 04:35
//
