// problem: https://leetcode.cn/problems/minimum-bit-flips-to-convert-number/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        return popcount(static_cast<unsigned>(start) ^ goal);
    }
};

int main(int argc, char *argv[]) {
    Solution test;
}

//
// Created By jing At 2026-05-04 20:31
//
