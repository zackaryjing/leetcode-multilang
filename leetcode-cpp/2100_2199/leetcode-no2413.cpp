// problem: https://leetcode.cn/problems/smallest-even-multiple/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int smallestEvenMultiple(int n) {
        return n & 1 ? n << 1 : n;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
}

//
// Created By jing At 2026-05-06 23:56
//
