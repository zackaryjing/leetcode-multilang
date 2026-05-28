// problem: https://leetcode.cn/problems/count-odd-numbers-in-an-interval-range/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        return (high - low + 1 + (high & 1)) >> 1;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
}

//
// Created By ASUS At 2026-05-28 14:36
//
